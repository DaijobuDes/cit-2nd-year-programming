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

    /* Check if user is logged in */
    if (!isset($_SESSION['logged_in']) || $_SESSION['logged_in'] == false) 
    {
        header("Location: login.php");
    }

    /* Create database csit201 */
    if ($conn->query("CREATE DATABASE csit201") === TRUE)
    {
        echo "<br />Database created.";
        $conn->close();
    }
    else
    {
        header("HTTP/1.1 500 Internal Server Error");
        echo "<br />An error occurred with reason: ".$conn->error;
    }
    
    $conn = mysqli_connect("localhost", "root", "", "csit201");

    /* Create tables */
    $information = "CREATE TABLE IF NOT EXISTS user_information (
        id INT(8) UNSIGNED AUTO_INCREMENT UNIQUE,
        firstname VARCHAR(32) NOT NULL,
        middlename VARCHAR(32) NOT NULL,
        lastname VARCHAR(32) NOT NULL,
        bmonth VARCHAR(2) NOT NULL,
        bday VARCHAR(2) NOT NULL,
        byear VARCHAR(4) NOT NULL,
        paddress VARCHAR(256) NOT NULL,
        country VARCHAR(32) NOT NULL,
        father_firstname VARCHAR(32) NOT NULL,
        father_middlename VARCHAR(32) NOT NULL,
        father_lastname VARCHAR(32) NOT NULL,
        mother_firstname VARCHAR(32) NOT NULL,
        mother_middlename VARCHAR(32) NOT NULL,
        mother_lastname VARCHAR(32) NOT NULL
        )";

    if ($conn->query($information) === TRUE)
        echo "<br />Table information created.";
    else
    {
        header("HTTP/1.1 500 Internal Server Error");
        echo "<br />An error occurred with reason: ".$conn->error;
        exit();
    }
    header("Location: fill_form.php");
?>