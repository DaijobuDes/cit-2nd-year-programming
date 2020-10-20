function checkForm() {
    var a = document.forms["form"]["firstname"].value;
    var b = document.forms["form"]["middlename"].value;
    var c = document.forms["form"]["lastname"].value;

    var d = document.forms["form"]["bmonth"].value;
    var e = document.forms["form"]["bday"].value;
    var f = document.forms["form"]["byear"].value;

    var g = document.forms["form"]["paddress"].value;
    var h = document.forms["form"]["country"].value;

    var i = document.forms["form"]["ffirstname"].value;
    var j = document.forms["form"]["fmiddlename"].value;
    var k = document.forms["form"]["flastname"].value;

    var l = document.forms["form"]["mfirstname"].value;
    var m = document.forms["form"]["mmiddlename"].value;
    var n = document.forms["form"]["mlastname"].value;

    if (
        a == "" || b == "" || c == "" ||
        d == "" || e == "" || f == "" ||
        g == "" || h == "" ||
        i == "" || j == "" || k == "" ||
        l == "" || m == "" || n == ""
    ) {
        alert("Please enter all fields.");
        return false;
    }
    return true;
}

