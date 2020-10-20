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
?>

<!DOCTYPE html>
<html>
    <head>
        <link rel="stylesheet" href="css/bootstrap.min.css" crossorigin="anonymous">
    </head>

    <body>
        

        

<?php

    error_reporting(E_ERROR | E_PARSE);
    /* Assume there's no database yet */
    $conn = mysqli_connect("localhost", "root", "");

    if (!$conn)
    {
        header("HTTP/1.1 400 Bad Request");
        echo '<div class="alert alert-danger" role="alert">';
        echo '  <h4 class="alert-heading">Connection Error</h4>';
        echo '  <p class="lead">There was a problem with the database.</p>';
        echo '  <hr />';
        echo '  <p class="mb-0">Reason: ' . mysqli_error($conn) . '</p>';
        echo '</div>';
        exit();
    }
    else
        header("HTTP/1.1 403 Forbidden");
    // else
    //     echo "<br />Connected to localhost.";

?>

    </body>


</html>