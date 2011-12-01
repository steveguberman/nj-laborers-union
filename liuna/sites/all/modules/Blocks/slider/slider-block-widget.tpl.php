<?php
/**
 * @file
 * Slider Block Widget Template
 *
 * Available Variables:
 * - $slides: An array of HTML list item strings. Just loop thru and echo.
 */
?>

<div id="liuna-slider">
	<span class="arrow back">
		<a href="#">&laquo;</a>
	</span>
	<span class="arrow forward">
		<a href="#">&raquo;</a>
	</span>

	<div class="slider-window">
		<ul id="slider-1" class="anythingBase">
			<?php foreach ($slides as $slide): ?>
				<?php echo $slide; ?>
			<?php endforeach; ?>
		</ul>
	</div>
</div>
