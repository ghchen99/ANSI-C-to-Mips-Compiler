

#start declaring a function
.global	f
.ent	f
.type	f,  @function
#finishing declaring a function

#start a function
f:
addiu	$sp,	$sp,	-152
sw	$31,	148($sp)
.cprestore	16
lui	$28,	%hi(__gnu_local_gp)
addiu	$28,	$28,	%lo(__gnu_local_gp)
lw	$t5,	%call16(g)($28)
move	$2,	$t0


#stacksize is152
lw	$31,	148($sp)
addiu	$sp,	$sp,	152
j	$ra
nop
#finishing a function


.end	f
#finishing

