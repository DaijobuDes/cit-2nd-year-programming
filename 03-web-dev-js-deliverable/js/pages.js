function welcomePage() {
    document.getElementById("welcomeText").innerHTML = "<center>Welcome to my<br />very special page.</center>";    
}

function changeBackground() {
    var bgcolorP = confirm("Want to change the background color?");
    var textcolorP = confirm("Want to change the font color?");

    if (bgcolorP) {
        var bgcolor = prompt("What background color?");
        
        if (textcolorP) {
            var textcolor = prompt("What text color?");
        }

        if (bgcolor == textcolor) {
            alert("You cant have the same color as a background.");
            return;
        }

        document.getElementById("bodycontent").style.backgroundColor = bgcolor;
        document.getElementById("textcontent").style.color = textcolor;
    }
}

function changeImage() {
    var image = document.getElementById("picture");
    /* Using CDN instead of local file */
    if (image.src == "https://daijobudes.s-ul.eu/YqAgLCDu") {
        image.src = "https://a.ppy.sh/12635292";
    }
    else if (image.src == "https://a.ppy.sh/12635292") {
        image.src = "https://daijobudes.s-ul.eu/YqAgLCDu";
    }
}

function getName() {
    var name = prompt("What's your name?", "name");
    document.getElementById("nameanswer").innerHTML = "Your name is " + name;
}

function getYear() {
    var year = prompt("What's your birthdate?", "0000");
    age = 2020 - year;
    document.getElementById("ageanswer").innerHTML = "Your age is " + age;
}

function psychoanalysis() {
    ans = prompt("How are you feeling?")
    /* Conditions start */
    /* Translate python code to javascript */
    if (ans == "I'm feeling down") {
        ans2 = prompt("Are you feeling down because of your job?");
        if (ans2 == "Yes" || ans2 == "yes") {
            ans3 = prompt("Why are you down?");
            if (ans3 == "I'm stressed") {
                alert("You need to rest a little bit, don't overstress yourself")
            } 
        }
        else if (ans2 != "yes" || ans2 != "Yes") {
            ans3 = prompt("Please state your reason");
            if (ans3) {
                alert("Seems you need a professional psychiatrist.")
            }
        }
        else {
            alert("That is not good at all")
        }
    }
    else if (ans == "I'm feeling happy") {
        ans2 = prompt("Are you happy because of your job?");
        if (ans2) {
            ans3 = prompt("Why are you happy?");
            if (ans3 == "I got promoted") {
                alert("Oh, very nice, keep up the good work");
            }
            else if (ans3 == "I got a raise") {
                alert("That's good my man, salary increased");
            }
            else {
                alert("That's good to hear, just keep up the good work");
            }
        }
        else {
            alert("Quiet or no answer, you are really happy");
        }
    }
    else {
        ans2 = prompt("Why are you feeling like that?");
        if (ans2) {
            ans3 = prompt("Why you do that anyway?");
            if (ans3) {
                alert("Probably you just need some rest. Take your time, don't rush");
            }
        }
        else {
            alert("I have nothing to say.");
        }
    }      
}