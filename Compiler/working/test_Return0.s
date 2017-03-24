

#start declaring a function
.global	f
.ent	f
.type	f,  @function
#finishing declaring a function

#start a function
f:
addiu	$sp,	$sp,	-10000
sw	$zero,	4($sp)
move	$2,	$0
addiu	$sp,	$sp,	+10000
j	$ra
nop
#finishing a function


#finishing

