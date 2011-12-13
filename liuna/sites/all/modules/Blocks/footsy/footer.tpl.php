<?php

// this should be in the theme preprocess but this is fine
// this also should use the form renderer function

function _linky($tree,$depth=-1,$depth_count=0){

$depth_count++;

$type = gettype($tree);


	foreach($tree as $name => $leaf){

		if($depth_count==1){
		echo '<div class="footer-div">';
		}
		echo '<ul class="footer-ul">';
			echo '<li class="level-'.$depth_count.'">';
			echo "<a href=".$leaf['path'].">$name</a>";
			echo '</li>';
				if( isset($leaf['children']) &&  ( $depth_count < $depth || $depth == -1) ) {
					_linky($leaf['children'],$depth,$depth_count);
				}

		echo '</ul>';
		if($depth_count==1){
		echo '</div>';
		}
	}
		
}
?>


<div id='footy-raptor-top'></div>
<?php _linky($links,3); ?>

<div id='footy-raptor-clear'>
</div>

