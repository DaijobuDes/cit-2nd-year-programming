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

    /* Convert all strings to uppercase */
    $_POST['firstname'] = strtoupper($_POST['firstname']);
    $_POST['middlename'] = strtoupper($_POST['middlename']);
    $_POST['lastname'] = strtoupper($_POST['lastname']);
    $_POST['bmonth'] = strtoupper($_POST['bmonth']);
    $_POST['bday'] = strtoupper($_POST['bday']);
    $_POST['byear'] = strtoupper($_POST['byear']);
    $_POST['paddress'] = strtoupper($_POST['paddress']);
    $_POST['country'] = strtoupper($_POST['country']);
    $_POST['ffirstname'] = strtoupper($_POST['ffirstname']);
    $_POST['fmiddlename'] = strtoupper($_POST['fmiddlename']);
    $_POST['flastname'] = strtoupper($_POST['flastname']);
    $_POST['mfirstname'] = strtoupper($_POST['mfirstname']);
    $_POST['mmiddlename'] = strtoupper($_POST['mmiddlename']);
    $_POST['mlastname'] = strtoupper($_POST['mlastname']);

    // $_POST['firstname']
    // $_POST['middlename']
    // $_POST['lastname']
    // $_POST['bmonth']
    // $_POST['bday']
    // $_POST['byear']
    // $_POST['paddress']
    // $_POST['country']
    // $_POST['ffirstname']
    // $_POST['fmiddlename']
    // $_POST['flastname']
    // $_POST['mfirstname']
    // $_POST['mmiddlename']
    // $_POST['mlastname']

    $sqlquery = "INSERT INTO user_information (
            firstname,
            middlename,
            lastname,
            bmonth,
            bday,
            byear,
            paddress,
            country,
            father_firstname,
            father_middlename,
            father_lastname,
            mother_firstname,
            mother_middlename,
            mother_lastname
        )
        VALUES (
            '". $_POST['firstname'] ."', 
            '". $_POST['middlename'] ."', 
            '". $_POST['lastname'] ."',
            '". $_POST['bmonth'] ."',
            '". $_POST['bday'] ."',
            '". $_POST['byear'] ."',
            '". $_POST['paddress'] ."',
            '". $_POST['country'] ."',
            '". $_POST['ffirstname'] ."', 
            '". $_POST['fmiddlename'] ."', 
            '". $_POST['flastname'] ."',
            '". $_POST['mfirstname'] ."', 
            '". $_POST['mmiddlename'] ."', 
            '". $_POST['mlastname'] ."'
        )
        ";

    while ($data = mysqli_fetch_assoc($result))
        if (
            $_POST['firstname'] == $data['firstname'] &&
            $_POST['middlename'] == $data['middlename'] &&
            $_POST['lastname'] == $data['lastname'] &&
            $_POST['bmonth'] == $data['bmonth'] &&
            $_POST['bday'] == $data['bday'] &&
            $_POST['byear'] == $data['byear'] &&
            $_POST['paddress'] == $data['paddress'] &&
            $_POST['country'] == $data['country'] &&
            $_POST['ffirstname'] == $data['father_firstname'] &&
            $_POST['fmiddlename'] == $data['father_middlename'] &&
            $_POST['flastname'] == $data['father_lastname'] &&
            $_POST['mfirstname'] == $data['mother_firstname'] &&
            $_POST['mmiddlename'] == $data['mother_middlename'] &&
            $_POST['mlastname'] == $data['mother_lastname']
        )
        {
            /* Returns 400 Bad Request */
            /* to tell if the record is duplicate */
            header("HTTP/1.1 400 Bad Request");
            echo '<div class="alert alert-warning" role="alert">';
            echo '  <h4 class="alert-heading">400 Bad Request</h4>';
            echo '  <p class="lead">Duplicate record found. Redirecting back in 3 seconds.</p>';
            echo '</div>';
            header("Refresh: 3, url=fill_form.php");
            exit();
        }            

    /* Check if the submission is empty */
    /* or if insert.php was accessed directly */
    if (
        $_POST['firstname'] == "" ||
        $_POST['middlename'] == "" ||
        $_POST['lastname'] == "" ||
        $_POST['bmonth'] == "" ||
        $_POST['bday'] == "" ||
        $_POST['byear'] == "" ||
        $_POST['paddress'] == "" ||
        $_POST['country'] == "" ||
        $_POST['ffirstname'] == "" ||
        $_POST['fmiddlename'] == "" ||
        $_POST['flastname'] == "" ||
        $_POST['mfirstname'] == "" ||
        $_POST['mmiddlename'] == "" ||
        $_POST['mlastname'] == ""
    )
    {
        /* Return 403 Forbidden status */
        header("HTTP/1.1 403 Forbidden");
        echo '<div class="alert alert-danger" role="alert">';
        echo '  <h4 class="alert-heading">403 Forbidden</h4>';
        echo '  <p class="lead">Blank submissions are not allowed. Redirecting back in 3 seconds.</p>';
        echo '</div>';
        header("Refresh: 3, url=fill_form.php");
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
    echo '  <p class="lead">Data added. Redirecting back in 3 seconds.</p>';
    echo '</div>';
    header("Refresh: 3, url=fill_form.php");
    mysqli_close($conn);
?>