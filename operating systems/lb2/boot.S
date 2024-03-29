.text

.set PROT_MODE_CSEG,0x8		# code segment selector
.set CR0_PE_ON,0x1			# protected mode enable flag
.set PROT_MODE_DSEG,0x10	# data segment selector
.globl start

start:
  # FIRST PHASE: Register y operation mode setup.
  # Assemble for 16-bit mode
  
	.code16  
        cli

	# Set up the important data segment registers (DS, ES, SS).
	xorw	%ax,%ax			# Segment number zero
	movw	%ax,%ds			# -> Data Segment
	movw	%ax,%es			# -> Extra Segment
	movw	%ax,%ss			# -> Stack Segment


	lgdt	gdtdesc		# load GDT: mandatory in protected mode
	movl	%cr0, %eax	# Turn on protected mode
	orl	$CR0_PE_ON, %eax
	movl	%eax, %cr0


    # CPU magic: jump to relocation, flush prefetch queue, and
	# reload %cs.  Has the effect of just jmp to the next
	# instruction, but simultaneously loads CS with
	# $PROT_MODE_CSEG.
	ljmp	$PROT_MODE_CSEG, $protcseg
	
	# weve switched to 32-bit protected mode; tell the assembler
	# to generate code for that mode
	.code32
protcseg:	

	# Set up the protected-mode data segment registers
	movw	$PROT_MODE_DSEG, %ax	# Our data segment selector
	movw	%ax, %ds		# -> DS: Data Segment
	movw	%ax, %es		# -> ES: Extra Segment
	movw	%ax, %fs		# -> FS
	movw	%ax, %gs		# -> GS
	movw	%ax, %ss		# -> SS: Stack Segment
	movb   $0x43,0xB8000 
	movb   $0x1E,0xB8001// 43 61 72 6c 6f 73
	movb   $0x61,0xB8002 
	movb   $0x1E,0xB8003
	movb   $0x72,0xB8004 
	movb   $0x1E,0xB8005
	movb   $0x6C,0xB8006 
	movb   $0x1E,0xB8007
	movb   $0x6F,0xB8008 
	movb   $0x1E,0xB8009
	movb   $0x73,0xB800A 
	movb   $0x1E,0xB800B
	call nombre
	
	
hang:
	jmp hang

.p2align 2			# force 4 byte alignment

gdt:	
gdt_null: 
	.word 0, 0						 
	.byte 0, 0, 0, 0 

gdt_code: 
	.word 0xFFFF , 0x0000 #Configuracion de Base y Limite del Segmento.
	.byte 0	#Esta linea es un tanto complicada pues estos 8 bits todavia forman parte
	.byte 0x9A
	.byte 0xCF 
    .byte 0 
gdt_data:    
        	.word 0xFFFF , 0x0000 
			.byte 0 
        	.byte 0x92 
        	.byte 0xCF 
        	.byte 0 
gdt_end:

gdtdesc:	.word	gdt_end - gdt - 1	# sizeof(gdt) - 1
			.long	gdt			# address gdt

