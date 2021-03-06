<?php
class Page{
	//class page's attribute
	//定义类里面的属性
	public $content;
	public $title = "TLA Consulting Pty Ltd";
	public $keywords = "TLA Consulting, Three Letter Abbreviation,
						some of my best friends are search engines";
	public $buttons = array("Home" => "home.php",
							"Contact" => "contact.php",
							"Services" => "services.php",
							"Site map" => "map.php");
	//class page's operations
	//定义方法 获取属性的方法
	public function __set($name, $value){
		$this->$name = $value;
	} 

	public function __get($name){
		return $this->$name;
	}

	//方法display是一个总的显示网页的方法
	public function Display(){
		echo "<html>\n<head>\n";
		$this-> DisplayTitle();
		$this-> DisplayKeywords();
		$this-> DisplayStyles();
		echo "<head>\n<body>\n";
		$this-> DisplayHeader();
		$this-> DisplayMenu($this->buttons);
		echo $this->content;
		$this-> DisplayFooter();
		echo "</body>\n</html>\n";
	}

	public function DisplayTitle(){
		echo "<title>".$this->title."</title>";
	}

	public function DisplayKeywords(){
		echo "<meta name=\"keywords\"
				content=\"".$this->keywords."\"/>";
	}


	//定义样式 可以用混写的方式，一旦开始混写前，一定要记得先？>来关闭php解析，完成html代码后，记得开启php 用<?php
	public function DisplayStyles(){

?>
	<style>
		h1 {
			color:yellow;font-size: 24pt; text-align: center;
			font-family: arial,sans-serif
		}
		.menu{
			color:yellow;font-size: 12pt;text-align: center;
			font-family: arial,sans-serif
		}
		td {
			background: black
		}
		p {
			color:black;font-size: 12pt;text-align: justify;
			font-family: arial,sans-serif
		}
		p.foot{
			color:white;font-size: 9pt;text-align: center;
			font-family: arial,sans-serif; font-weight: bold
		}
		a:link,a:visited, a:active{
			color:white;
		}
	</style>

<?php
	}

	public function DisplayHeader(){
?>
	<table width="100%" cellpadding="12"
			cellspacing="0" border="0">
	<tr bgcolor="black">
		<td align="left"><img src="image/logo.gif"/></td>
		<td>
			<h1>
				TLA Consulting Pty Ltd
			</h1>
		</td>
		<td align="right"><img src="image/logo.gif"/></td>
	</tr>
	</table>

<?php
	}

	public function DisplayMenu($buttons){
		echo "<table width=\"100%\" bgcolor=\"white\"
				cellpadding=\"4\" cellspacing=\"4\"
				>\n";
		echo "<tr>\n";

	//calculate button size
		$width = 100/count($buttons);
		while(list($name,$url) = each($buttons)){
			$this-> DisplayButton($width, $name, $url,!$this->IsURLCurrentPage($url));
		}

		echo "</tr>\n";
		echo "</table>\n";
	}

	public function IsURLCurrentPage($url){
		if(strpos($_SERVER['PHP_SELF'],$url) == false){
			// sprintf($_SERVER['PHP_SELF']);
			// print_r($_SERVER['PHP_SELF']);
			return false;
		}
		else{
			return true;
		}
	}
	//			<img src=\"image/side-logo.gif\">*<img src=\"image/s-logo.gif\" alt=\"".$name."\" border=\"0\" />
	public function DisplayButton($width, $name, $url, $active=true){
		if($active){
			echo "<td width = \"".$width."%\">
			<a href=\"".$url."\">
			</a>
			<a href=\"".$url."\"><span class=\"menu\">".$name."</span></a></td>";
		}else{
			echo "<td width=\"".$width."%\">

			<span class=\"menu\">".$name."</span>
			</td>";
		}
	}

	public function DisplayFooter(){
?>	
<table width="100%" bgcolor="black" cellpadding="12" border="0">
<tr>
	<td>
		<p class="foot">&copy; TLA Consulting Pty Ltd.</p>
		<p class="foot">Please see our <a href="">legal information page</a></p>
	</td>
</tr>
</table>
<?php
	}
}
?>
