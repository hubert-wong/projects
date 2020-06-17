/*------------------------Functions for Slideshow Begin---------------------------------*/
var slide_index = 1;
displayslides(slide_index);

function moveslide(x)
{
    displayslides(slide_index += x);
}

function slidey(x)
{
    displayslides(slide_index = x);
}

function displayslides(x)
{
    var i;
    var slides = document.getElementsByClassName("slide");
    var dots = document.getElementsByClassName("dot");
    if(x > slides.length)
    {
        slide_index = 1;
    }
    if(x < 1)
    {
        slide_index = slides.length;
    }
    for(i = 0; i < slides.length; i++)
    {
        slides[i].style.display = "none";
    }
    for(i = 0; i < dots.length; i++)
    {
        dots[i].className = dots[i].className.replace(" active", "");
    }
    slides[slide_index - 1].style.display = "block";
    dots[slide_index - 1].className += " active";
}

/*------------------Functions for Slideshow End-----------------------------------------*/

/*--------------------Functions for Return to Top Button Begin--------------------------*/
var mybutton = document.getElementById("button");

window.onscroll = function() {scrollFunction()};

function scrollFunction()
{
    if(document.body.scrollTop > 20 || document.documentElement.scrollTop > 20)
    {
        mybutton.style.display = "block";
    }
    else
    {
        mybutton.style.display = "none";
    }
}

function topFunction()
{
    document.body.scrollTop = 0;
    document.documentElement.scrollTop = 0;
}
/*--------------------Functions for Return to Top Button End----------------------------*/

/*--------------------Clock Function Begin----------------------------------------------*/
const HOURHAND = document.querySelector("#hour");
const MINUTEHAND = document.querySelector("#minute");
const SECONDHAND = document.querySelector("#second");

var date = new Date();
console.log(date);
let hr = date.getHours();
let min = date.getMinutes();
let sec = date.getSeconds();
console.log("Hour: " + hr + " Minute: " + min + " Second: " + sec);

let hrPosition = (hr*360/12)+(min*(360/60)/12);
let minPosition = (min*360/60)+(sec*(360/60)/60);
let secPosition = sec*360/60;

function runTheClock() {

    hrPosition = hrPosition+(3/360);
    minPosition = minPosition+(6/60);
    secPosition = secPosition+6;

    HOURHAND.style.transform = "rotate(" + hrPosition + "deg)";
    MINUTEHAND.style.transform = "rotate(" + minPosition + "deg)";
    SECONDHAND.style.transform = "rotate(" + secPosition + "deg)";
}
var interval = setInterval(runTheClock, 1000);

function currentTime()
{
    var date = new Date(); /* creating object of Date class */
    var hour = date.getHours();
    var min = date.getMinutes();
    var sec = date.getSeconds();
    hour = updateTime(hour);
    min = updateTime(min);
    sec = updateTime(sec);
    if(hour > 12)
    {
        document.getElementById("digital_clock").innerText = (hour-12) + " : " + min + " : " + sec + " PM";
    }
    else
    {
        document.getElementById("digital_clock").innerText = (hour) + " : " + min + " : " + sec + " AM";
    }
    var t = setTimeout(function(){ currentTime() }, 1000); /* setting timer */
}

function updateTime(k) {
    if (k < 10) {
      return "0" + k;
    }
    else {
      return k;
    }
  }

currentTime(); /* calling currentTime() function to initiate the process */
/*--------------------Clock Function End------------------------------------------------*/

/*-------------------------Current Task Function Begin----------------------------------*/

const task = document.querySelector(".currenttask a");

task.classList.remove("hide");

function reveal(e,current) {
    var date = new Date(); /* creating object of Date class */
    var hour = date.getHours();
    var string;
    if(hour > 18)
    {
        string = "Since it is after 6:00 PM, I'm probably coding.";
    }
    else if(hour < 9)
    {
        string = "Since it is before 9:00 AM, I'm probably sleeping.";
    }
    else
    {
        string = "Since I'm not sleeping or coding right now, I'm probably hanging out with friends, studying, or playing games. Who knows?";
    }
    e.preventDefault();
    current.innerHTML == "Click on me to learn what I'm doing right now!" ? task.innerHTML = string : task.innerHTML = "Click on me to learn what I'm doing right now!";
}

task.addEventListener('click', function(e){ reveal(e,this);}, false);

/*---------------------------Current Task Function End----------------------------------*/

/*----------------------------Copyright things at the end-------------------------------*/
const to_print = document.querySelector(".copyright a");

function show()
{
    var date = new Date();
    var year = date.getFullYear();
    to_print.innerHTML = "&copy; Hubert Wong, " + year + ". All rights Reserved";
}

show();