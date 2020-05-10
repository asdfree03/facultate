set talk off
clear
close all
use comanda.dbf
index on codc to ccodc
index on codf to ccodf
index on codm to ccodm
index on codp to ccodp
use
use medicament.dbf
index on codm to mcodm
index on codf to mcodf
use
use farmacie.dbf
index on codf to fcodf
index on nume to fnume
use
use comanda.dbf in 1 alias com
use farmacie.dbf in 2 alias farm
use medicament.dbf in 3  alias med
use plata.dbf in 4 alias pl
SET TALK OFF
DO WHILE.T.
 CLEAR
TEXT
 FUNCTII OFERITE:
1- Adaugare Farmacie
2- Adaugare Medicament
3- Adaugare Comanda
4- Afiseaza toate medicamentele din categoria antibiotice vandute de farmacia Catena
5- Afiseaza toate farmaciile impreuna cu comenzile lor
6- Sterge din baza de date toate produsele care au stocul egal cu 0
7- Afisarea tuturor tabelelor
T- Terminare program
ENDTEXT
WAIT TO R
do rbas
IF.NOT. R $ '1234567Tt'
 ? 'FUNCTIA ' + R + ' inexistenta'
 WAIT
 LOOP
ENDIF
DO CASE
 CASE R='1'
 vid = val(accept("Introduceti cod farmacie"))
 vnume = trim(accept("Introduceti numele farmaciei"))
 vadresa = trim(accept("Introduceti adresa farmaciei"))
 vnr= trim(accept("Introduceti telefonul"))
 DO adaugaFarmacie with vid,vnume,vadresa,vnr
 case R='2'
	vid = val(accept("Introduceti cod medicament"))
 vnume = trim(accept("Introduceti numele medicamentului"))
 vcat = trim(accept("Introduceti categoria medicamentului"))
 vstoc= val(accept("Introduceti stocul"))
 vfarm = trim(accept("Introduceti farmacia"))
 DO adaugaMedicament with vid,vnume,vcat,vstoc,vfarm
 case R='3'
	vid = val(accept("Introduceti cod comanda"))
	vdat=CTOD(ACCEPT('Data {ll/zz/aa}'))
 vcant = val(accept("Introduceti cantitatea"))
 vmed= trim(accept("Introduceti medicamentul"))
 vfarm = trim(accept("Introduceti farmacia"))
 DO adaugaComanda with vid,vdat,vcant,vmed,vfarm
 case R='4'
	do p4
 case R='5'
	do p5
 case R='6'
	do p6
	case R='7'
use comanda.dbf in 1 alias com
use farmacie.dbf in 2 alias farm
use medicament.dbf in 3  alias med
use plata.dbf in 4 alias pl
	select 1
	list
	select 2
	list
	select 3
	list
	select 4
	list
	wait
	use
 case R $'Tt'
	use
	close all
	return
endcase
enddo

procedure rbas
select 1
close all
use comanda.dbf excl
reindex
use
select 2
close all
use farmacie.dbf excl
reindex
use
select 3
close all
use medicament.dbf excl
reindex
use
return

procedure adaugaFarmacie
use comanda.dbf in 1 alias com
use farmacie.dbf in 2 alias farm
use medicament.dbf in 3  alias med
use plata.dbf in 4 alias pl
	parameters vid,vnume,vadresa,vnr
	use farmacie.dbf
	append BLANK
	replace CodF with vid, nume with vnume, adresa with vadresa, nr_tel with vnr
	use
return

procedure adaugaMedicament
use comanda.dbf in 1 alias com
use farmacie.dbf in 2 alias farm
use medicament.dbf in 3  alias med
use plata.dbf in 4 alias pl
	parameters vid,vnume,vcat,vstoc,vfarm
	select 2
	set index to fnume
	seek vfarm
	select 3
	append BLANK
	replace CodM with vid, nume with vnume, categorie with vcat, stoc with vstoc,codf with farm->codf
	use
return

procedure adaugaComanda
use comanda.dbf in 1 alias com
use farmacie.dbf in 2 alias farm
use medicament.dbf in 3  alias med
use plata.dbf in 4 alias pl
	parameters vid,vdat,vcant,vmed,vfarm
	use farmacie.dbf
	locate for nume = vfarm
	vnfarm = codF
	use
	use medicament.dbf
	locate for nume = vmed
	vnmed = codM
	use plata.dbf
	count to nri
	vcodp = nri+1
	vsuma = val(accept("Introduceti suma"))
	vtip = trim(accept("Introduceti tipul(card/cash)"))
	vstare = "neachitat"
	append blank
	replace codp with vcodp, suma with vsuma, tip with vtip, stare with vstare
	use
	use comanda.dbf
	append BLANK
	replace CodC with vid, data with vdat, cantitate with vcant, codm with vnmed,codf with vnfarm, codp with vcodp
	use
return

procedure p4
set exact on
select 3
close all
use medicament.dbf excl
reindex
use
use comanda.dbf in 1 alias com
use farmacie.dbf in 2 alias farm
use medicament.dbf in 3  alias med
use plata.dbf in 4 alias pl
	select 2
	set index to fnume
	seek "Catena"
	set index to fcodf
	select 3
	set relation to codf into farm constr
	set index to mcodf
	do while med->categorie = "Antibiotice" .and. med->codf = farm->codf
	?med->nume,med->categorie,med->stoc
	skip
	enddo
	wait
	use
	set exact off
return
procedure p5
use comanda.dbf in 1 alias com
use farmacie.dbf in 2 alias farm
use medicament.dbf in 3  alias med
use plata.dbf in 4 alias pl
	select 2
	set index to fcodf
	do while .not. eof()
		select 1
		set index to ccodf
		?farm->nume
		seek farm->codf
		do while com->codf = farm->codf
			?com->data,com->cantitate
		skip
		enddo
		select 2
	skip
	enddo
	wait
	use
return

procedure p6
use comanda.dbf in 1 alias com
use farmacie.dbf in 2 alias farm
use medicament.dbf in 3  alias med
use plata.dbf in 4 alias pl
	select 3
	scan for stoc = 0
	set delete on
	delete
	endscan
	select 3
	close all
	use medicament.dbf excl
	pack
	use
	use medicament.dbf in 3 alias med
	wait
	use
return