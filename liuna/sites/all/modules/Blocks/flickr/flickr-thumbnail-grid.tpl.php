<?php
/**
 * @file
 * Default implementation of the Flickr Thumbnail Grid template. Assembles an unordered list 
 * of photos based on an array returned by the Flickr API client class.
 *
 * Available Variables:
 * - $photos: An associative array of photos w/ width, height, source, url, and 
 * label properties
 * - $api_key: the Flickr API key (in case we need to do subsequent API calls)
 *
 * @see template_preprocess()
 * @see template_preprocess_flickr_thumbnail_grid()
 */
?>

<ul id="flickr-thumbnail-grid">
	<?php foreach ($photos as $thumb): ?>
		<?php if (!isset($thumb['width'])) continue; ?>
		<li class="flickr-thumb">
			<a href="<?php echo $thumb['url']; ?>" class="photo-wrap <?php echo $thumb['class']; ?>">
				<img src="<?php echo $thumb['source']; ?>" width="<?php echo $thumb['width']; ?>" height="<?php echo $thumb['height']; ?>" alt="<?php echo $thumb['label']; ?>"/>
			</a>
		</li>
	<?php endforeach; ?>
</ul>
