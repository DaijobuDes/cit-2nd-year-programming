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

    $conn->query("USE csit201");

    /* Check if user is logged in */
    session_start();
    if (!isset($_SESSION['logged_in']) || $_SESSION['logged_in'] == false) 
    {
        header("Location: login.php");
    }

    $result = $conn->query("SELECT * FROM user_information");

    $sqlquery = "DELETE FROM user_information 
        WHERE id = '". $_POST['dbid'] . "'
        ";

    if ($_POST['dbid'] == "")
    {
        header("HTTP/1.1 400 Bad Request");
        echo '<div class="alert alert-warning" role="alert">';
        echo '  <h4 class="alert-heading">400 Bad Request</h4>';
        echo '  <p class="lead">Attempted to submit an empty value. Redirecting back in 3 seconds.</p>';
        echo '</div>';
        header("Refresh: 3; url=db_info.php");
        exit();
    }

    if (!is_numeric($_POST['dbid']))
    {
        header("HTTP/1.1 400 Bad Request");
        echo '<div class="alert alert-warning" role="alert">';
        echo '  <h4 class="alert-heading">400 Bad Request</h4>';
        echo '  <p class="lead">Invalid input, expected int. Redirecting back in 3 seconds.</p>';
        echo '</div>';
        header("Refresh: 3; url=db_info.php");
        exit();
    }

    if (!$conn->query($sqlquery))
    {
        header("HTTP/1.1 400 Bad Request");
        echo '<div class="alert alert-warning" role="alert">';
        echo '  <h4 class="alert-heading">400 Bad Request</h4>';
        echo '  <p class="lead">Reason: ' . mysqli_error($conn) . '. Redirecting back in 3 seconds.</p>';
        echo '</div>';
        header("Refresh: 3; url=fill_form.php");
        // die("Error: ".mysqli_error($conn));
        exit();
    }

    /* Return 200 OK */
    /* to tell if the record insertion was a success */
    header("HTTP/1.1 200 OK");
    echo '<div class="alert alert-success" role="alert">';
    echo '  <h4 class="alert-heading">200 OK</h4>';
    echo '  <p class="lead">Data deleted. Redirecting back in 3 seconds.</p>';
    echo '</div>';
    header("Refresh: 3, url=db_info.php");
    mysqli_close($conn);


?>