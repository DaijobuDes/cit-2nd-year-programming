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
    $result = $conn->query("SELECT * FROM user_information");
?>

<!DOCTYPE html>
<html>
    <head>
        <!-- Required meta tags -->
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
        <meta http-equiv="pragma" content="no-cache" />
        <!-- <meta http-equiv="refresh" content="2"> -->

        <!-- Bootstrap CSS -->
        <link rel="stylesheet" href="css/bootstrap.min.css" integrity="sha384-TX8t27EcRE3e/ihU7zmQxVncDAy5uIKz4rEkgIXeMed4M0jlfIDPvg6uqKI2xXr2" crossorigin="anonymous">

        <link rel="stylesheet" href="css/form.css" />

        <script src="js/checker.js"></script>

        <title>Show/Delete Data</title>
    </head>
    <body>
        <!-- Navigation Bar -->
        <ul class="nav nav-tabs nav-justified">
            <li class="nav-item">
                <a class="nav-link" href="./fill_form.php">Encode Form</a>
            </li>
            <li class="nav-item">
                <a class="nav-link active" href="./db_info.php">Show/Delete Database</a>
            </li>
            <li class="nav-item">
                <a class="nav-link" href="./logout.php">Logout</a>
            </li>
        </ul>

        <br />
        <form action="delete.php" method="POST" name="form">
            <div class="form-row" id="names">
                <p class="lead">Delete by Database ID: &nbsp;</p>

                <div class="form-group mx-sm-2 mb-0">
                    <input type="number" class="form-control" id="dbid" name="dbid"></input>
                </div>
                <input type="submit" class="btn btn-danger text-nowrap btn-sm" value="Submit" id="button_submit" onclick="return confirm('Do you want to delete that?');"></input>
                <p class="lead"><a href="drop.php" style="margin-left: 10em;" onclick="return confirm('Do you want to purge the database?')">Click here to purge all tables.</a></p>
            </div>  
        </form>

        <form action="form_update.php" method="GET" name="form">
            <div class="form-row" id="names">
                <p class="lead">Update by Database ID: &nbsp;</p>

                <div class="form-group mx-sm-2 mb-0">
                    <input type="number" class="form-control" id="dbid" name="dbid"></input>
                </div>
                <input type="submit" class="btn btn-danger text-nowrap btn-sm" value="Submit" id="button_submit"></input>
            </div>  
        </form>
        <br />


        <table class="table table-bordered table-hover table-sm">
            <thead class="thead-dark">
                <tr>
                    <th>Index</th>
                    <th>Database ID</th>
                    <th>First Name</th>
                    <th>Middle Name</th>
                    <th>Last Name</th>
                    <th>MM</th>
                    <th>DD</th>
                    <th>YYYY</th>
                    <th>Address</th>
                    <th>Country</th>
                    <th>Father&apos;s Name</th>
                    <th>Mother&apos;s Name</th>
                </tr>
            </thead>

        <?php
            $i = 1;
            while ($data = mysqli_fetch_assoc($result))
            {
                echo "<tbody>";
                echo "  <tr>";
                echo "      <th scope='row'>". $i . "</th>";
                echo "      <td>" . $data['id'] . "</td>";
                echo "      <td>" . $data['firstname'] . "</td>";
                echo "      <td>" . $data['middlename'] . "</td>";
                echo "      <td>" . $data['lastname'] . "</td>";
                echo "      <td>" . $data['bmonth'] . "</td>";
                echo "      <td>" . $data['bday'] . "</td>";
                echo "      <td>" . $data['byear'] . "</td>";
                echo "      <td>" . $data['paddress'] . "</td>";
                echo "      <td>" . $data['country'] . "</td>";
                echo "      <td>" . $data['father_lastname'] . ", " . $data['father_firstname'] . " " . $data['father_middlename'] . "</td>";
                echo "      <td>" . $data['mother_lastname'] . ", " . $data['mother_firstname'] . " " . $data['mother_middlename'] . "</td>";
                echo "  </tr>";
                echo "</tbody>";
                $i++;
            }

        ?>

        </table>
    </body>
</html>