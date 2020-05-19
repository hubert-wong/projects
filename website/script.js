
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