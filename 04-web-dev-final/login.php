<?php
/*

MIT License

Copyright (c) 2020 Kate Aubrey Cellan (Maine Ichinose)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

    require_once("config.php");

    session_start();
    
    $conn->query("USE csit201");

    $result = $conn->query("SELECT * FROM users");

    $data = mysqli_fetch_assoc($result);

    if (isset($_SESSION['logged_in']) && $_SESSION['logged_in'] === true) 
    {
        header("Location: create.php");
    }

    if ($_POST['username'] == "" || $_POST['password'] == "")
    { 
            echo '<div class="alert alert-warning alert-dismissible fade show" role="alert">';
            echo '  <strong>Empty Password!</strong> You entered an empty password.';
            echo '  <button type="button" class="close" data-dismiss="alert" aria-label="Close">';
            echo '      <span aria-hidden="true">&times;</span>';
            echo '  </button>';
            echo '</div>';
    }

    if (isset($_POST['username']) && isset($_POST['password'])) 
    {
        if ($_POST['username'] == $data['username'] && $_POST['password'] == $data['password']) 
        {
            $_SESSION['logged_in'] = true;
            header("Location: create.php");
        }
        else 
        {
            echo '<div class="alert alert-warning alert-dismissible fade show" role="alert">';
            echo '  <strong>Incorrect Password!</strong> You should recheck what you have typed.';
            echo '  <button type="button" class="close" data-dismiss="alert" aria-label="Close">';
            echo '      <span aria-hidden="true">&times;</span>';
            echo '  </button>';
            echo '</div>';
        }
    }

?>

<!DOCTYPE html>
<html lang="en">
    <head>
        <!-- Required meta tags -->
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
        <meta http-equiv="pragma" content="no-cache" />
        <!-- <meta http-equiv="refresh" content="2"> -->

        <!-- Bootstrap CSS -->
        <link rel="stylesheet" href="css/bootstrap.min.css" integrity="sha384-TX8t27EcRE3e/ihU7zmQxVncDAy5uIKz4rEkgIXeMed4M0jlfIDPvg6uqKI2xXr2" crossorigin="anonymous">

        <link rel="stylesheet" href="css/login.css" />
        <script src="js/jquery-3.5.1.slim.min.js" integrity="sha384-DfXdz2htPH0lsSSs5nCTpuj/zy4C+OGpamoFVy38MVBnE+IbbVYUew+OrCXaRkfj" crossorigin="anonymous"></script>
        <script src="js/bootstrap.bundle.min.js" integrity="sha384-ho+j7jyWK8fNQe+A12Hb8AhRq26LrZ/JpcUGGOn+Y7RsweNrtN/tE3MoK7ZeZDyx" crossorigin="anonymous"></script>

        <title>Login</title>
    </head>

    <body>
        <div class="loginBox">
            <form method="POST" action="login.php">
                Username: <br />
                <input type="text" name="username"><br />
                Password: <br />
                <input type="password" name="password"><br />
                <input type="submit" class="btn btn-outline-primary" id="loginBtn" value="Login"></input><input type="reset" class="btn btn-outline-danger" id="resetBtn" value="Reset"></input>
            </form>
        </div>
    </body>
<html>
    