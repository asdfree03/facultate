set talk off
clear
close all
use pasageri
index on codc to icodcp
index on cnp to icnp
use
use curse
index on codc to icodc
use
use tehnic.dbf
index on codt to icodt
use
clear
use curse in 1 index iCodc alias curse
use pasageri in 2 index iCodcP alias pasageri
use tehnic in 3 index iCodt alias tehnic
select curse
set relation to codc into pasageri constrain
DO WHILE.T.
 CLEAR
TEXT
 FUNCTII OFERITE:
1- Rezervare
2- Afisare pasageri
3- Statistica
4- Cautare dupa cod cursa
T- Terminare program
ENDTEXT
WAIT TO R
IF.NOT. R $ '1234Tt'
 ? 'FUNCTIA ' + R + ' inexistenta'
 WAIT
 LOOP
ENDIF
DO CASE
 CASE R='1'
 vcodc = trim(accept("Introduceti cod cursa"))
 vcnp = trim(accept("Introduceti cnp"))
 vnume = trim(accept("Introduceti numele"))
 vadresa = trim(accept("Introduceti adresa"))
 vdat=CTOD(ACCEPT('Data {ll/zz/aa} nasterii'))
 vtel= trim(accept("Introduceti telefonul"))
 vpret= val(accept("Introduceti pretul"))
 DO adaugaPasager with vcodc,vcnp,vnume,vadresa,vdat,vtel,vpret
 case R='2'
	vcodc = trim(accept("Introduceti cod cursa"))
 DO afisarePasageri with vcodc
 case R='3'
	select c.codc,c.oras1,c.oras2,count(p.codc),sum(p.pret);
 from curse c,pasageri p where p.codc=c.codc;
 group by c.codc,c.oras1,c.oras2 alias stat
 //use stat in 4
 list
 wait
 use
 case R='4'
	do p4
 case R $'Tt'
	close all
	return
endcase
enddo
procedure p4
	select 1
	cod=trim(accept("introduceti codul cursei"))
	seek cod
	if found()
	?'Oras 1 = ',oras1,'Ora 1 = ',ora1,'Oras 2 = ',oras2;
	,'Ora 2 = ',ora2,'Tip Avion = ',TipA
	select 3
	seek curse->codp
	?"Pilot = ",nume
	seek curse->codp2
	?"Co-Pilot = ",nume
	else
		msgbox("Cursa "+cod+" nu exista!")
 endif
 wait
return

procedure adaugaPasager
 parameters vcodc,vcnp,vnume,vadresa,vdat,vtel,vpret
  select 2
 codcc=vcodc 
 seek codcc 
 if found()
 append blank
 replace codc with codcc
 replace cnp with vcnp
 replace numep with vnume
 replace adresa with vadresa
 replace datan with vdat
 replace tel with vtel
 replace pret with vpret
 endif
 select 1
 seek codcc
 if found()
 replace nrloc with nrloc-1 
 endif
 msgbox("Rezervare efectuata!")
 return
 
 procedure afisarePasageri
 parameters vcodc
 use ftemp exclusive in 4
 select 4 
 delete all
 pack
 select 1
 cod = vcodc
 seek cod
 if found()
 ?'Oras 1 = ',oras1,'Ora 1 = ',ora1,'Oras 2 = ',oras2;
	,'Ora 2 = ',ora2,'Tip Avion = ',TipA
 select 3
 seek curse->codp
	?"Pilot = ",nume
	seek curse->codp2
	?"Co-Pilot = ",nume
endif
select 2 
seek cod
if found()
do while .not. eof(2) .and. codc=cod
select 4
append blank 
 replace cnp with pasageri->cnp
 replace numep with pasageri->numep
 replace adresa with pasageri->adresa
 replace datan with pasageri->datan
 replace tel with pasageri->tel
 replace pret with pasageri->pret
 select 2
 skip
 enddo
 use ftemp
 list
 wait
 use
 endif
 return