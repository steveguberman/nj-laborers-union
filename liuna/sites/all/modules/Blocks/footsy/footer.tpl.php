<?php

// this should be in the theme preprocess but this is fine
// this also should use the form renderer function

function _linky($tree,$depth=-1,$depth_count=0){

$depth_count++;

$type = gettype($tree);


		echo '<ul class="footer-links">';
	foreach($tree as $name => $leaf){
		echo '<li class="level-'.$depth_count.'">';
		echo "<a href=".$leaf['path'].">$name</a>";
		echo '</li>';
			if( isset($leaf['children']) &&  ( $depth_count < $depth || $depth == -1) ) {
				_linky($leaf['children'],$depth,$depth_count);
			}
	}
		
		echo '</ul>';
}
?>

<h1>footy</h1>


<?php _linky($links); ?>
