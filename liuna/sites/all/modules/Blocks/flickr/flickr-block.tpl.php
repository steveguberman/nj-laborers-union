<?php
/**
 * Flickr Photo Grid Block
 *
 * Renders a Flickr feed (as serialized PHP) into a grid of thumbnails with links to the original image.
 */
if (isset($items)) {
	pretty_r($items);
} else {
	pretty_r("No items var");
}
?>
