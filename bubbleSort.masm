; gemaakt door: Michael Scholten
; datum: 17-1-2021
.code

bsort8 proc
	; controleer of rdx gelijk is aan 0 en ga direct naar het einde als dat het geval is.
	cmp rdx, 0
	jle endloop
	; geef rax de waarde 1
	mov rax, 1
sortloop:
	; geef bx de 16 bit waarde op de locatie aangegeven door rcx
	mov bx, word ptr[rcx]
	; als de waarde van de lagere byte van register b lager is dan de hogere byte, wissel de waardes.
	cmp bl, bh
	jg switch
	; verhoog de waarde van rcx en rax
	inc rcx
	inc rax
	; als rax lager is dan rdx, dan begint de loop opnieuw, anders komen we vanzelf bij het einde.
	cmp rax, rdx
	jl sortloop
endloop:
	ret
switch:
	; geef de waarde van bh aan de byte op de locatie aangegeven door rcx en verhoog rcx om de waarde van bl op de volgende geheugenlocatie te plaatsen.
	mov byte ptr [rcx], bh
	inc rcx
	mov byte ptr [rcx], bl
	; controleer of rax kleiner dan of gelijk aan 0 is, verhoog de waarde van rax als dat het geval is.
	cmp rax, 0
	jle increase
	; verlaag de waarde van rax met 1 en de waarde van rcx met 2 om de waarde verhoging te corrigeren en rcx een extra omlaag te brengen.
	dec rax
	sub rcx, 2
	; ga naar het begin van de loop
	jmp sortloop
increase:
	; verhoog de waarde van rax en ga terug naar het begin van de loop
	inc rax
	jmp sortloop
bsort8 endp

bsort16 proc
	; vergelijk rdx met 0 en ga naar het einde als dat het geval is.
	cmp rdx, 0
	jle endloop
	; geef rax de waarde 1 en geef register 8 de waarde van rcx om rcx vrij te maken.
	mov rax, 1
	mov r8, rcx
sortloop:
	; geef bx de 16 bit waarde op de locatie aangegeven door r8, verhoog r8 met 2 en geef cx de waarde op de nieuwe locatie aangegeven door r8.
	mov bx, word ptr[r8]
	add r8, 2
	mov cx, word ptr[r8]
	; vergelijk bx en cx met elkaar en verwissel de waardes als bx > cx
	cmp bx, cx
	jg switch
	; verhoog rax en vergelijk de waarde van rax met de waarden in rdx. Als rax kleiner is dan rdx, ga je terug naar het begin en anders kom je vanzelf bij het einde.
	inc rax
	cmp rax, rdx
	jl sortloop
endloop:
	ret
switch:
	; geef de locatie aangegeven door r8 de waarde van bx, verlaag r8 met 2 en geef de nieuwe locatie de waarde van cx.
	mov word ptr [r8], bx
	sub r8, 2
	mov word ptr [r8], cx
	; vergelijk rax met 0, verhoog rax en rcx met 2 als rax <= 0.
	cmp rax, 0
	jle increase
	; verlaag rax, verlaag r8 met 2 en ga naar het begin van de loop
	dec rax
	sub r8, 2
	jmp sortloop
increase:
	; verhoog rax met 1, verhoog r8 met 2 en ga naar het begin van de loop.
	inc rax
	add r8, 2
	jmp sortloop
bsort16 endp

end