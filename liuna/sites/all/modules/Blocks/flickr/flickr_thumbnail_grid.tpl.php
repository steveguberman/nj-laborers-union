<ul id="flickr-thumbnail-grid">
	<?php foreach ($items['items'] as $photo): ?>
		<li class="flickr-thumb">
			<a href="<?php echo $photo['url']; ?>" class="photo-wrap <?php echo $photo['class']; ?>">
				<img src="<?php echo $photo['source']; ?>" width="<?php echo $photo['width'] / 2; ?>" height="<?php echo $photo['height'] / 2; ?>" alt="<?php echo $photo['label']; ?>" />
			</a>
		</li>
	<?php endforeach; ?>
</ul>
