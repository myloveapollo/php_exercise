function do_html_header($title){
// print an HTML header
?>
<html>
<head>
	<title><?php echo $title;?></title>
	<style>
		body {font-family:Arial, Helvetica, sans-serif;font-size:13px}
		li, td {font-family:Arial, Helvetica, sans-serif; font-size:13px}
		hr {color:#3333cc; width=300px; text-align:left}
		a {color:#000000}
	</style>
</head>
<body>
	<img src="bookmark.gif" alt="PHPbookmark logo" border='0'
		align="left" valign="bottom" height="55" width="57"/>
	<h1>PHPbookmark</h1>
	<hr/>
<?php
	if($title){
		do_html_heading($title);
	}
}