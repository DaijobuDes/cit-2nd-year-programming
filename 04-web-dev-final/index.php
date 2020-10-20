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

    $loginSystem = "CREATE TABLE IF NOT EXISTS users (
        id INT(16) UNSIGNED NOT NULL UNIQUE AUTO_INCREMENT,
        username VARCHAR(16) NOT NULL UNIQUE,
        password VARCHAR(256) NOT NULL UNIQUE
        )";

    $users = "INSERT INTO users (
        username,
        password
    )
    VALUES (
        'admin',
        'admin'
    )
    ";

    if ($conn->query($loginSystem) === TRUE)
        echo "<br />Table Login System created.";
    else
    {
        header("HTTP/1.1 500 Internal Server Error");
        echo "<br />An error occurred with reason: ".$conn->error;
        exit();
    }

    if ($conn->query($users) === TRUE)
        echo "<br />Data inserted.";

    header("Location: login.php");
 
?>