const Discord = require('discord.js');
const {prefix, token} = require('./config.json');
const ytdl = require('ytdl-core');
const client = new Discord.Client();
const queue = new Map();

client.once('ready', () => {
    console.log('I am ready baby!')
});


client.on('guildMemberAdd', member => {
    const channel = member.guild.channels.cache.find(ch => ch.name === 'general');
    if(!channel) return;
    channel.send(`Ew cringe, ${member} has joined. Gross.`);
});

//special commands to be implemented
client.on('message', message => {
    if(message.content.startsWith(`${prefix}ping`))
    {
        message.channel.send("pong!");
    }

    if(message.author.bot) return;
    if(!message.content.startsWith(prefix)) return;
                //music bot portion//
    const server_q = queue.get(message.guild.id);
    if(message.content.startsWith(`${prefix}play`))
    {
        execute(message, server_q);
        return;
    }
    else if(message.content.startsWith(`${prefix}skip`))
    {
        skip(message, server_q);
    }
    else if(message.content.startsWith(`${prefix}stop`))
    {
        stop(message, server_q);
    }
    else
    {
        const msg = message.content;
        message.channel.send(`the command: **${msg}** has not been implemented yet! coming soon...:face_with_hand_over_mouth: `);
    }
});

async function execute(message, serverQueue) {
    const args = message.content.split(" ");
  
    const voiceChannel = message.member.voice.channel;
    if (!voiceChannel)
      return message.channel.send(
        "You need to be in a voice channel to play music!"
      );
    const permissions = voiceChannel.permissionsFor(message.client.user);
    if (!permissions.has("CONNECT") || !permissions.has("SPEAK")) {
      return message.channel.send(
        "I need the permissions to join and speak in your voice channel!"
      );
    }
  
    const songInfo = await ytdl.getInfo(args[1]);
    const song = {
      title: songInfo.title,
      url: songInfo.video_url
    };
  
    if (!serverQueue) {
      const queueContruct = {
        textChannel: message.channel,
        voiceChannel: voiceChannel,
        connection: null,
        songs: [],
        volume: 5,
        playing: true
      };
  
      queue.set(message.guild.id, queueContruct);
  
      queueContruct.songs.push(song);
  
      try {
        var connection = await voiceChannel.join();
        queueContruct.connection = connection;
        play(message.guild, queueContruct.songs[0]);
      } catch (err) {
        console.log(err);
        queue.delete(message.guild.id);
        return message.channel.send(err);
      }
    } else {
      serverQueue.songs.push(song);
      return message.channel.send(`${song.title} has been added to the queue!`);
    }
  }
  
  function skip(message, serverQueue) {
    if (!message.member.voice.channel)
      return message.channel.send(
        "You have to be in a voice channel to stop the music!"
      );
    if (!serverQueue)
      return message.channel.send("There is no song that I could skip!");
    serverQueue.connection.dispatcher.end();
  }
  
  function stop(message, serverQueue) {
    if (!message.member.voice.channel)
      return message.channel.send(
        "You have to be in a voice channel to stop the music!"
      );
    serverQueue.songs = [];
    serverQueue.connection.dispatcher.end();
  }
  
  function play(guild, song) {
    const serverQueue = queue.get(guild.id);
    if (!song) {
      serverQueue.voiceChannel.leave();
      queue.delete(guild.id);
      return;
    }
  
    const dispatcher = serverQueue.connection
      .play(ytdl(song.url))
      .on("finish", () => {
        serverQueue.songs.shift();
        play(guild, serverQueue.songs[0]);
      })
      .on("error", error => console.error(error));
    dispatcher.setVolumeLogarithmic(serverQueue.volume / 5);
    serverQueue.textChannel.send(`Currently playing: **${song.title}**`);
  }


client.login(token);