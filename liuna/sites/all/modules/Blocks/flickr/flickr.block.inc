<?php

function template_preprocess_flickr_thumbnail_grid(&$variables) {
	$photos = array();
	$flickr = new Flickr($variables['api_key']);
	foreach ($variables['items'] as $photo) {
		if (!isset($photo['id'])) continue;
		$data = @$flickr->get_sizes($photo['id']);
		$photos[] = $data;
	}
	$variables['photos'] = $photos;
}

//vim: set ft=php :
?>
