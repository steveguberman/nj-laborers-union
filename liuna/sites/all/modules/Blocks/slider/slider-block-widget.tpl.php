<?php
/**
 * @file
 * Slider Block Widget Template
 *
 * Available Variables:
 * - $slides: An array of HTML list item strings. Just loop thru and echo.
 */
?>

<ul id="liuna-slider">
	<?php foreach ($slides as $slide): ?>
		<?php echo $slide; ?>
	<?php endforeach; ?>
</ul>
<ul id="slider-thumbnails">
</ul>
<div class="clear"></div>
