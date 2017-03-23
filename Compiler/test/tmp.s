

#start declaring a function
.global	main
.ent	main
.type	main,  @function
#finishing declaring a function

#start a function
main:
addiu	$sp,	$sp,	-40
sw	$zero,	4($sp)
lw	$t0,	4($sp)
move	$2,	$t0
addiu	$sp,	$sp,	+40
j	$ra
nop
#finishing a function


#finishing
