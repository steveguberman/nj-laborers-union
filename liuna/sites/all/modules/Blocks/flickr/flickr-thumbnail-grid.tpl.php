<?php
/**
 * @file
 * Default Flickr thumbnail grid block implementation. Displays an unordered list of image
 * thumbnails, with links leading to the full sized images on Flickr.
 *
 * Available Variables:
 * $feed_url: URL to the originating Flickr feed.
 * $num_photos: The number of photos to display.
 * $photos: An array of photos, with each photo represented by an associative array.
 */
?>

<ul id="flickr-thumbnail-grid">
	<?php
	foreach ($photos as $idx => $photo):
		if ($idx > $num_photos) break;
	?>
	<li class="flickr-thumb">
		<?php echo $photo['description']; ?>
	</li>
	<?php endforeach; ?>
</ul>
