
.globl _start
_start:
  # FIRST PHASE: Register y operation mode setup.
  # Assemble for 16-bit mode
  .code16 
        cli
	# The BIOS loads this code from the first sector of the hard disk into
	# memory at physical address 0x7c00 and starts executing in real mode
	# with %cs=0 %ip=7c00.
        movw     $0x07C0,%ax 
        movw     %ax, %ds
        movw     %ax, %es
        movw     %ax, %fs
        movw     %ax, %gs

	#Stack Initialization
        movw     $0x0000 , %ax 
        movw     %ax, %ss
        movw     $0xFFFF,%sp
        sti
   
    #readline

      #  mov     $0x0000, %ah
       # int     $0x16    
        #movb     $0x0E,%ah 	#Bios Teletype,This number must be used to 
				#tell the BIOS to put a character on the screen
        #movb     $0x00,%bh 	#Page number (For most of our work this will remain 0x00)
       # movb     $0x08,%bl      #Text attribute (For most of our work this will remain 0x07) 
				#Try to change this value
    #    int      $0x10  	#BIOS video interrupt. 
	
	    	#SECOND PHASE: a C program that would load the
				#kernel into memory.
    mov $0x0000, %bl
    mov $0x0000, %cl
    #readline
    ReadPrintLine: 
    mov $0x000, %ah    #activamos en ah 0x0000 que es el servicio que necesitamos de la interrupcion 16
    int $0x16          #interrupcion 16 -> Almacena en %al
    movb $0x0E, %ah    #activamos la funcion para la interrupcion 10
    int  $0x10         #interrupcion 10 -> Almacena en %al
    cmpb $0x0D, %al    #compare si es enter
    jne  ReadPrintLine
    mov  $10, %al
    movb $0x0E, %ah
    int $0x10
    call ReadPrintLine


# Bootstrap GDT
.p2align 2                                # force 4 byte alignment
.data                   # section declaration

msg:
    .word 0x0D        # length of our dear string



