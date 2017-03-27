

#start declaring a globalvariable
.global	x
.data
.type	x,  @object
.size	x,  4
x:
.word	( ( 10 * 10 ) - 1 )
#finished declaring a globalvariable




#start declaring a function
.global	main
.ent	main
.type	main,  @function
#finishing declaring a function

#start a function
main:
addiu	$sp,	$sp,	-156
sw	$zero,	4($sp)
addi	$t1,	$zero,	20
sw	$t1,	4($sp)
lw	$t1,	4($sp)
addi	$t1,	$zero,	1
sw	$t1,	4($sp)
lui	$t1,	%hi(x)
lw	$t1,	%lo(x)($t1)
sw	$t1,	8($sp)
lw	$t1,	4($sp)
sw	$t1,	12($sp)
lw	$t0,	8($sp)
lw	$t1,	12($sp)
add	$t1,	$t0,	$t1
move	$t0,	$t1
move	$2,	$t0


#stacksize is156
addiu	$sp,	$sp,	156
j	$ra
nop
#finishing a function


.end	main
#finishing

