

#start declaring a globalvariable
.global	x
.data
.type	x,  @object
.size	x,  4
x:
.word	( ( 10 * 10 ) - 1 )
#finished declaring a globalvariable




#start declaring a function
.global	f
.ent	f
.type	f,  @function
#finishing declaring a function

#start a function
f:
addiu	$sp,	$sp,	-80
sw	$31,	76($sp)
lui	$t0,	%hi(x)
lw	$t0,	%lo(x)($t0)
move	$2,	$t0


#stacksize is80
lw	$31,	76($sp)
addiu	$sp,	$sp,	80
j	$ra
nop
#finishing a function


.end	f
#finishing

