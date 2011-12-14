<?php
$address	= $info['address'];
$type		= $info['type'];
$contact	= $info['contact'];
$website	= $info['website'];
?>

<ul class='union-link'>
<li> <a href='http://google.com'>Benifits</a> </li>
<li> <a href='http://google.com'>Training</a> </li>
</ul>

<HR>

<ul  class='union-info'>
<?php if($address){ ?>
<li id='union-address'>
<?php echo $address ?>
</li>
<?php } ?>

<?php if($type){ ?>
<li id='union-type'>
<?php echo $type ?>
</li>
<?php } ?>

<?php if($contact){ ?>
<li id='union-contact'>
<?php echo $contact?>
</li>
<?php } ?>

<?php if($website){ ?>
<li id='union-website'>
<?php echo $website?>
</li>
<?php } ?>
</ul>

<HR>
