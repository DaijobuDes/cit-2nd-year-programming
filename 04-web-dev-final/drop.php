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

    /* Check if user is logged in */
    session_start();
    if (!isset($_SESSION['logged_in']) || $_SESSION['logged_in'] == false) 
    {
        header("Location: login.php");
    }

    $conn->query("USE csit201");

    /* Truncate table instead of recreating one. (DROP) */
    /* Let the keyword or DB function do its job. */
    $conn->query("TRUNCATE TABLE user_information");

    echo '<div class="alert alert-danger" role="alert">';
    echo '  <h4 class="alert-heading">Database Purged</h4>';
    echo '  <p class="lead">All data were removed. Redirecting back in 3 seconds.</p>';
    echo '</div>';
    header("HTTP/1.1 301 Moved Permanently");
    header("Refresh: 3; url=db_info.php");


?>
