<?php
/**
 * Flickr Photo Grid Block
 *
 * Renders a Flickr feed (as serialized PHP) into a grid of thumbnails with links to the original image.
 */
?>
<h1>Flickr Feed</h1>
<?php echo $variables['elements']['#markup']; ?>
<?php pretty_r($variables); ?>
