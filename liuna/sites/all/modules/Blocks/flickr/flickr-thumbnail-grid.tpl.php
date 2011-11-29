<ul id="flickr-thumbnail-grid">
	<?php pretty_r($photos); ?>
	<?php foreach ($photos as $thumb): ?>
		<?php
		$width = $thumb['width'] / 2;
		$height = $thumb['height'] / 2;
		?>
		<li class="flickr-thumb">
			<a href="<?php echo $thumb['url']; ?>" class="photo-wrap <?php echo $thumb['class']; ?>">
				<img src="<?php echo $thumb['source']; ?>" width="<?php echo $width; ?>" height="<?php echo $height; ?>" alt="<?php echo $thumb['label']; ?>"/>
			</a>
		</li>
	<?php endforeach; ?>
</ul>
