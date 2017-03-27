

#start declaring a function
.global	f
.ent	f
.type	f,  @function
#finishing declaring a function

#start a function
f:
addiu	$sp,	$sp,	-76
addiu	$t0,	$zero,	10
move	$2,	$t0


#stacksize is76
addiu	$sp,	$sp,	76
j	$ra
nop
#finishing a function


.end	f
#finishing

