

#start declaring a function
.global	ffff
.ent	ffff
.type	ffff,  @function
#finishing declaring a function

#start a function
ffff:
addiu	$sp,	$sp,	-124
sw	$31,	120($sp)
sw	$zero,	4($sp)
lw	$t1,	4($sp)
li	$t1,	10
sw	$t1,	4($sp)
lw	$t0,	4($sp)
move	$2,	$t0


#stacksize is124
lw	$31,	120($sp)
addiu	$sp,	$sp,	124
j	$ra
nop
#finishing a function


.end	ffff
#finishing

