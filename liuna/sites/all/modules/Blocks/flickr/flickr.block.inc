<?php

function template_preprocess_flickr_thumbnail_grid(&$variables) {
	$photos = array();
	$flickr = new Flickr($variables['api_key']);

	// For each photo, grab the "small" size version and replace its URL attribute with the Original size's URL
	foreach ($variables['items'] as $photo) {
		if (!isset($photo['id'])) continue;
		$data            = @$flickr->get_sizes($photo['id']);
		$thumb           = $data[0];
		$thumb['url']    = $data[count($data)-1]['url'];
		$thumb['width']  = $thumb['width'];
		$thumb['height'] = $thumb['height'];
		$photos[]        = $thumb;
	}
	$variables['photos'] = $photos;
}

//vim: set ft=php :
?>
