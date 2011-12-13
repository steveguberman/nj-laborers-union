<?php


function template_preprocess_footer(&$variables){
	$tree = menu_tree_all_data('taxnav_menu');
	$tree = _simple_tree($tree);

	$variables['links'] = $tree;
}


function _simple_tree($tree){
	$out=array();
	foreach($tree as $leaf){
		$out[$leaf['link']['link_title']]['path'] = $leaf['link']['link_path'];
			if($leaf['below']){
			$out[$leaf['link']['link_title']]['children'] = _simple_tree($leaf['below']);
			}
	}

		return $out;
}


// vim : set ft=php :
?>
