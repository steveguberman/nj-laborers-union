<?php
/**
 * @file
 * Default template for the Flickr Drive Box block widget.
 *
 * Available Variables:
 * - $photos: An associative array of photos w/ width, height, source, url, and 
 * label properties
 * - $api_key: the Flickr API key (in case we need to do subsequent API calls)
 *
 * @see template_preprocess()
 * @see template_preprocess_flickr_drive_thumbnail_list()
 */
?>

<?php #pretty_r($photos); ?>
<?php if (0 < count($photos)): ?>
	<ul id="flickr-drive-box">
		<?php foreach ($photos as $photo): ?>
			<?php if (!isset($photo['width'])) continue; ?>
			<li>
				<a href="<?php echo $photo['url']; ?>" target="_blank">
					<img src="<?php echo $photo['source']; ?>" width="<?php echo $photo['width']; ?>" height="<?php echo $photo['height']; ?>" alt="<?php echo $photo['label']; ?>" />
				</a>
			</li>
		<?php endforeach; ?>
	</ul>
<?php endif; ?>
