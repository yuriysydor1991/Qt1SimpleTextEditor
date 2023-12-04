/*
 * Copyright (c) 2023, Yurii Sydor (yuriysydor1991@gmail.com) kytok.org.ua
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *     Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON  ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS  SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "FilterCreator.h"

namespace {
/*
 * Thanks to
 * https://www.file-extensions.org/filetype/extension/name/text-files
 * https://www.file-extensions.org/filetype/extension/name/source-code-and-script-files/
 * for providing ALL the text files extensions available.
 */
static constexpr const char* defaultFileFilter =
    "All files (*)\n"
    "Text files (*.txt *.ini *.conf *.xml *.json *.md)\n"
    "Tables text files (*.csv *tsv)\n"
    "Project files (README LICENSE AUTHORS .gitignore OWNERS WATCHLISTS "
    "DEPS UPDATING RELNOTES MAINTAINERS COPYRIGHT Makefile)\n"
    "Known text files ("
    "*.enc *.txt *.srt *.ris *.cm0013 *.1 *.vtt *.html *.vmg *.csv *.asc "
    "*.xml *.plist *.xlog *.ass "
    "*.sub *.rdf *.arff *.lst *.conf *.iif *.adoc *.asp *.textclipping "
    "*.wrl *.tbl *.htm *.bas *.md "
    "*.rtf *.text *.manifest *.tsv *.pgw *.pod *.ascii *.xfd *.log *.pl "
    "*.report *.xmp *.smi *.reg "
    "*.las *.html5 *.ver *.yml *.application *.diz *.ffp *.mtx *.tce "
    "*.label *.dtd *.xsd *.linux *.xlf "
    "*.wer *.dbt *.smali *.aml *.att *.fpt *.nfo *.sbv *.lst *.bss *.full "
    "*.pdu *.drp *.ansi *.android "
    "*.extra *.mf *.gen *.err *.brf *.xy *.en *.ecsv *.sha1 *.us *.fsa "
    "*.tfw *.modd *.igy *.sdnf *.s19 "
    "*.ldf *.sfb *.eia *.zib *.bog *.strings *.ltx *.ipr *.srx *.ba1 *.lrc "
    "*.xdp *.ac *.ru *.rff *.mp3 "
    "*.xff *.annot *.xsl *.fr *.artask *.crash *.opml *.ion *.nt *.ans "
    "*.diskdefines *.resp *.alx *.wkf "
    "*.tt *.new *.lin *.ssa *.isi *.rus *.clg *.emulecollection *.readme "
    "*.utf8 *.uk *.rt *.mw *.vzm "
    "*.spx *.xslt *.adl *.s2k *.1st *.sha512 *.pjs *.rml *.lisp *.markdown "
    "*.desc *.oot *.tlx *.odc "
    "*.prn *.gnu *.clipping *.dea *.soap *.idt *.dqy *.ja *.pac *.fin *.bnx "
    "*.tdump *.not *.gbf *.ger "
    "*.bna *.xdl *.skv *.spec *.lnc *.rtx *.mit *.pln *.blm *.lyr *.coo "
    "*.rest *.cof *.efm *.srt *.dk "
    "*.textile *.dpv *.vhdl *.lwd *.klg *.isr *.bcr *.pcl *.vfk *.zed "
    "*.edml *.st1 *.pla *.enf *.etf "
    "*.map *.plk *.notes *.bpdx *.cd2 *.$00 *.dok *.ocr *.usf *.zhp *.mkdn "
    "*.user *.asp *.ltr *.crwl "
    "*.nbr *.opc *.pvw *.tcm *.chord *.lxfml *.jeb *.ort *.etx *.txt *.wst "
    "*.jtx *.bln *.first *.uhtml "
    "*.dat *.lst *.ctl *.jp1 *.it *.prc *.mib *.bsdl *.hvc *.txe *.frm "
    "*.rea *.ext *.prr *.$01 *.phr "
    "*.de *.vcf *._me *.dne *.sami *.faq *.lo_ *.wsh *.txt *.dkz *.vw "
    "*.text *.vhd *.hhc *.dfe *.pmo "
    " *.tle *.aqt *.nna *.uni *.xwp *.ssf *.gthr *.htx *.htmls *.$02 *.ctl "
    "*.usg *.tab *.bdp *.ddd "
    "*.qdt *.kor *.vers *.ckn *.inuse *.adw *.ttbl *.charset *.x70 *.maxfr "
    "*.ltt *.dmr *.osn *.unx "
    "*.kch *.txk *.bep *.guide *.aprj *.89t *.dectest *.assoc *.blw *.x20 "
    "*.x80 *.nlc *.bea *.map *.qud "
    "*.xc0 *.skcard *.txh *.awa *.q&a *.tx8 *.kix *.crd *.thp *.txd *.now "
    "*.bbs *.mcw *.mdwn *.mss *.utx "
    "*.dp *.lue *.hs *.luf *.big5 *.soundscript *.mathml *.wn *.omn *.hz "
    "*.wtx *.ttpl *.tph *.$04 *.iem "
    "*.rtl *.fnx *.$ol *.sk *.hhs *.vkp *.mkd *.hlm *.zw *.tab *.tnef "
    "*.ttxt *.igv *.pc5 *.snw *.lst *.p3x "
    "*.cdt *.xsr *.psb *.gpl *.ill *.clix *.lst *.csassembly *.trt *.bdn "
    "*.txa *.linx *.ttf *.rst *.seq *.spg "
    "*.fff *.jam *.utxt *.hpm *.mar *.nmbd *.mdown *.mpl *.vxml *.ctx *.oh "
    "*.mdle *.u3i *.001 *.tmx *.tdf "
    "*.unauth *.mdtext *.dfm *.zxe *.tx? *.smf *.$o1 *.abt *.trn *.dii "
    "*.gtx *.pfs *.jis *.adt *.asl *.lst "
    "*.big *.adiumlog *.jam *.es *.x60 *.idx *.cc *.plf *.wrd *.openbsd "
    "*.cas *.cil *.hdr *.ted *.mez *.82t "
    "*.nokogiri *.bt *.oogl *.cif *.fil *.curl *.nwctxt *.csmanifest *.dcd "
    "*.la *.inc *.xhtm *.pd *.tm *.lay "
    "*.man *.flr *.$05 *.mtx *.bel *.adiumhtmllog *.v2t *.bk *.inc *.jss "
    "*.xwp *.dsml *.tgf *.tbd *.t *.xyz "
    "*.dsc *.spn *.mtxt *.xyp *.lyt *.vna *.me *.bad *.jam *.t2t *.sms "
    "*.ojp *.text *.pcc *.vsmproj *.panic "
    "*.tlb *.mdtxt *.ctf *.dce *.axt *.ctd *.awb *.9xt *.vis *.id31 *.nclk "
    "*.x90 *.awh *.ion *.cho *.bdr "
    "*.vw3 *.rzn *.euc *.idc *.tte *.cag *.tmprtf *.pvj *.7 *.sen *.bbxt "
    "*.fra *.s2s *.mpsub *.pml *.cli "
    "*.pt3 *.syn *.xyw *.tlx *.osi *.pro *.bzw *.kahl *.set *.hlx "
    " *.8 *.gdt *.rzk *.92t *.id32 *.lst *.apx *.igtx *.pbd *.uax *.fon "
    "*.xy3 *.tpl *.vet *.stq *.cascii *.cs "
    "*.awp *.sct *.box *.inc *.box *.rbdf *.8xt *.awd *.hp8 *.rel *.sgp "
    "*.hsk *.ivp *.abl *.zanebug *.spa *.nvgp "
    "*.ion *.txa *.xd0 *.fmr *.xb0 *.npdt *.gluaw *.k2edoc *.hm12 *.cff "
    "*.des *.ini "
    " *.aspx *.json *.do *.jsp *.ser *.ino *.s *.xml *.gcode *.aia *.ino "
    " *.rpy *.py *.php *.rdf *.c *.jsf *.atomsvc *.o *.asp *.pdb "
    " *.mrc *.jad *.asm *.htm *.sh *.bas *.h *.r *.js *.cpp "
    " *.lib *.m *.rpyc *.p *.lxk *.sln *.rcc *.action *.lua *.toml "
    " *.bat *.pyc *.c3p *.pod *.abs *.luac *.sal *.asta *.vbs *.asi "
    " *.src *.cs *.pickle *.pl *.mom *.scb *.graphml *.mlx *.xla *.fs "
    " *.ins *.html5 *.faces *.nupkg *.ips *.mst *.mf *.cfm *.ws *.idb "
    " *.sasf *.ss *.arxml *.rss *.gradle *.ejs *.rss *.fmb *.dtd *.xsd "
    " *.mdp *.axd *.mm *.liquid *.f *.prg *.c# *.scs *.luca *.bp "
    " *.jsc *.mac *.tcl *.install *.resources *.smali *.cls *.mwp *.cc "
    "*.java "
    " *.spr *.gp *.ptx *.mrl *.d *.csb *.ema *.yaml *.jdp *.vlx "
    " *.e *.fas *.inc *.pm *.yyp *.cgi *.perl *.brml *.bash *.txx "
    " *.wiki *.mc *.dbg *.csproj *.derp *.jav *.atp *.sfx *.fil *.wbf "
    " *.swift *.pmp *.ave *.wbt *.scss *.jsa *.dvb *.ckm *.history *.beta "
    " *.cod *.run *.go *.agc *.l *.pyo *.coverage *.rpg *.cms *.kt "
    " *.bml *.io *.asic *.loc *.mq4 *.dsd *.pf3 *.vls *.x *.resx "
    " *.stm *.pyt *.pas *.bal *.isa *.cmake *.eld *.dwarf *.ipr *.rc "
    " *.mzp *.rbf *.gbl *.cpb *.nvi *.geojson *.eaf *.sax *.prl *.mhl "
    " *.matlab *.lsp *.sct *.mvba *.xsl *.xlm *.hbs *.csc *.vbe *.sm "
    " *.bdt *.ebc *.hs *.xaml *.inp *.nt *.arb *.v4e *.lap *.ml "
    " *.ipb *.re *.form *.classpath *.plx *.scr *.psm1 *.lmp *.script *.aps "
    " *.cxx *.ptl *.gs *.mfa *.login *.pdml *.rfs *.gv *.groovy *.lis "
    " *.mrd *.ahk *.vba *.jsx *.ps1 *.jse *.scpt *.sl *.lnk *.ppam "
    " *.pjt *.mo *.command *.nse *.vcxproj *.mhm *.vbp *.cspkg *.xcp *.mk "
    " *.rb *.phtml *.mw *.vip *.a5r *.rbt *.dwt *.dpr *.mq5 *.dist "
    " *.ptxml *.rpym *.xslt *.phl *.dtx *.pyw *.pbl *.c++ *.tra *.dbml "
    " *.au3 *.hdf *.xcl *.dlg *.ats *.as *.moc *.j *.lub *.csx "
    " *.ti *.lst *.wdl *.hc *.trig *.f90 *.el *.diff *.cpr *.mlv "
    " *.seam *.rml *.proto *.lisp *.less *.bcp *.obj *.pag *.egg-info "
    "*.rule "
    " *.cbl *.dep *.isu *.lss *.vb *.wsdl *.ppa *.vd *.dev *.build "
    " *.bb *.jl *.txml *.bxml *.odc *.lol *.bbc *.scb *.rh *.cobol "
    " *.gml *.datasource *.jsdtscope *.cml *.jbi *.ide *.pdo *.aidl *.cg "
    "*.gnt "
    " *.dqy *.bsc *.tpl *.dts *.dbp *.gch *.hxp *.nbk *.qs *.gcl "
    " *.twig *.dpk *.lpx *.mkb *.btq *.shfbproj *.hpf *.hx *.exp *.pl "
    " *.pbl *.pbxproj *.fwx *.uix *.thtml *.vbi *.lds *.qry *.kd *.psd1 "
    " *.vcp *.bgm *.hkp *.cbp *.ipf *.cson *.iml *.kts *.mg *.arq "
    " *.ssi *.brs *.rkt *.mak *.ada *.bmo *.sca *.depend *.irb *.asz "
    " *.uvproj *.bax *.master *.styl *.mrs *.nk *.targets *.srz *.pyx *.zrx "
    " *.dproj *.tru *.amw *.param *.factorypath *.jade *.tmh *.wml *.pch "
    "*.kv "
    " *.cob *.mec *.apb *.mel *.vbx *.gvy *.ror *.akt *.textile *.tpm "
    " *.inp *.obj *.coveragexml *.axs *.owl *.wsf *.rob *.bms *.idl *.tkp "
    " *.gypi *.dob *.kmt *.cx *.sdl *.pym *.vbscript *.clm *.aiml *.vpc "
    " *.btproj *.xme *.bcc *.dso *.hlsl *.abap *.htc *.ocb *.xui *.edml "
    " *.fountain *.rproj *.cos *.pxml *.pli *.din *.xn *.kst *.cpz "
    "*.svn-base "
    " *.f95 *.cd *.a2w *.trt *.mscr *.ttl *.dbmdl *.cgx *.scala *.ps2 "
    " *.m *.d4 *.greenfoot *.frt *.xpdl *.zsc *.ary *.uvprojx *.gss *.cp "
    " *.jardesc *.cbs *.rdf *.wpk *.tgml *.ulp *.asc *.rc2 *.awd *.zpd "
    " *.vbw *.ecore *.shit *.bsv *.wsdd *.ksh *.ssq *.gyp *.rhtml *.m6m "
    " *.ash *.rej *.tk *.sxs *.tcz *.wxs *.vup *.osg *.cuh *.dpd "
    " *.a *.dhtml *.tik *.ksc *.vjp *.qvs *.xbs *.jml *.gfa "
    " *.jsonp *.xjb *.poc *.fsi *.rts *.xul *.irobo *.cba *.sass *.devpak "
    "*.autosave "
    " *.lba *.dot *.viw *.irc *.mfl *.odl *.rws *.thor *.gls *.htr "
    " *.scm *.dgml *.clojure *.cla *.ipy *.mediawiki *.bur *.wsc *.mat "
    "*.wfs "
    " *.fxml *.php3 *.dfd *.zws *.g1m *.applet *.dfb *.ebx *.opv *.tea "
    " *.ph *.pkb *.txl *.4ge *.jks *.exe_ *.clw *.es6 *.bzs *.mod "
    " *.ncb *.vap *.common *.coffee *.bpo *.xproj *.jcw *.mx *.opl *.wxl "
    " *.dto *.dic *.hic *.agi *.lnx *.bet *.xin *.sqlproj *.appxmanifest "
    "*.fxl "
    " *.hms *.mpx *.ctl *.nhs *.xib *.xpb *.ogx *.stl *.tdo *.ppml "
    " *.robo *.com_ *.vc6 *.ascx *.ccs *.dml *.pou *.ii *.msha *.swg "
    " *.gsk *.rpo *.vim *.snippet *.sus *.m51 *.pdb *.s *.eze *.mly "
    " *.prg *.fcmacro *.hoic *.rs *.jacl *.bpr *.vpi *.autoplay *.msc *.cod "
    " *.kx *.geany *.ump *.svo *.mls *.fsx *.cxe *.cxs *.hxx *.sami "
    " *.airi *.ghp *.wpj *.cs *.mako *.zsh *.nbin *.wsh *.vbhtml *.rptproj "
    " *.s5d *.ogr *.ilk *.res *.bxl *.sbr *.enml *.kex *.xr *.ji "
    " *.mcp *.amos *.j3d *.ig *.mod *.jak *.p6 *.make *.rrc *.cshrc "
    " *.xfm *.lhs *.prg *.makefile *.ppo *.ucb *.sas *.vstemplate *.fbp "
    "*.zero "
    " *.qsc *.vbproj *.oqy *.vrp *.jsfl *.cls *.atmn *.kodu *.jcl *.rub "
    " *.lnp *.ftn *.actionscript *.appxsym *.slim *.bbf *.ncx *.tlh *.fgb "
    "*.chef "
    " *.csh *.hse *.lmv *.rbw *.v *.pnproj *.jtb *.oppo *.rgs *.alan "
    " *.owl *.cfi *.sno *.xnf *.classdiagram *.ipch *.vcproj *.smw *.xda "
    "*.hei "
    " *.ev3p *.npi *.ba_ *.psc1 *.okm *.pba *.phs *.tur *.myapp *.cplist "
    " *.git *.plog *.ccproj *.cls *.cel *.jex *.gek *.psml *.lsh *.rmn "
    " *.asmx *.win32manifest *.xtxt *.ck *.afb *.cfs *.appxupload *.jgs "
    "*.xml-log *.ttcn "
    " *.gfe *.psl *.vbg *.pb *.cgi *.hbm *.gxl *.scm *.gus *.vddproj "
    " *.jcs *.4pk *.bsh *.was *.xlv *.wmw *.sltng *.tql *.ssc *.phps "
    " *.ex *.gobj *.atmx *.wpm *.lml *.vdp *.dba *.zpl *.dse *.ses "
    " *.cfo *.fasl *.nes *.c-- *.dlg *.fsproj *.ob2 *.wxi *.jss *.fpi "
    " *.csh *.pl7 *.maki *.vsmacros *.clj *.vc15 *.pgm *.ox *.tsq *.xsql "
    " *.vdproj *.pspscript *.rnw *.m4 *.qpf *.iss *.grxml *.ogs *.ebs2 "
    "*.bsml "
    " *.scz *.zfd *.tli *.v3s *.tikz *.m2r *.pmod *.fcg *.res *.phpt "
    " *.s43 *.resjson *.vssscc *.for *.hsm *.haml *.wli *.pl6 *.ebs *.bhs "
    " *.msl *.php1 *.saas *.bdh *.bs2 *.vtm *.a3c *.pbi *.rbp *.sjc "
    " *.mbas *.itcl *.pri *.nlc *.rdoc *.appcache *.sqo *.ew *.orl *.p5 "
    " *.mash *.ttinclude *.m3 *.wbc *.ins *.asax *.brx *.xv2 *.awk *.pql "
    " *.xig *.mb *.frs *.bxp *.hom *.bml *.nls *.bte *.acu *.psu "
    " *.jsb *.bin_ *.c__ *.rpres *.jbp *.hxproj *.anjuta *.idle *.fcgi "
    "*.exw "
    " *.nmk *.sbh *.kix *.ogl *.thml *.ywl *.itmx *.hbx *.obr *.hrl "
    " *.mc *.goc *.acgi *.simba *.mss *.pro *.cfml *.tzs *.tcsh "
    "*.entitlements "
    " *.nas *.maml *.b24 *.ekm *.cphd *.mnd *.rvt *.rxs *.pom *.hxa "
    " *.ane *.avsi *.pawn *.exu *.mcml *.php2 *.hla *.chh *.kcl *.fuc "
    " *.c86 *.arnoldc *.lsp *.aml *.pr7 *.ju *.ipf *.~pa *.licx *.f03 "
    " *.gc3 *.gemfile *.ik *.kon *.rbx *.jug *.pf1 *.owx *.gdg *.pfx "
    " *.exsd *.ked *.s4e *.epl *.nsi *.jsh *.bsm *.pkh *.mss *.glade "
    " *.syp *.iap *.ebs *.buildpath *.aem *.mqt *.qxm *.rqy *.rc3 *.mxe "
    " *.zts *.ago *.fus *.rvb *.wdw *.ms *.tec *.qac *.fmx *.xlm_ "
    " *.ass *.jcm *.4gl *.kit *.xrc *.wdproj *.wam *.vsixmanifest *.ajm "
    "*.b2d "
    " *.tla *.dsb *.licenses *.bufferedimage *.sbml *.xblr *.cord *.dcproj "
    "*.ebm *.map "
    " *.mmb *.neko *.mmh *.19 *.mln *.pro *.mfps *.daemonscript *.rake "
    "*.image "
    " *.hxml *.dcf *.axb *.reb *.jsxinc *.a8s *.playground *.pfa *.ldz "
    "*.ts0 "
    " *.yxx *.graphmlz *.ahtml *.pjx *.scar *.komodo *.ss *.11 *.javajet "
    " *.msh1xml *.rqb *.aah *.elc *.lamp *.lpr *.udf *.creole *.po *.ezg "
    "*.vala "
    " *.a2x *.dsym *.pp1 *.scriptterminology *.confluence *.rqc *.pwo "
    "*.xojo_binary_project *.p4a *.asp "
    " *.configure *.uih *.jmk *.mdex *.vgc *.genmodel *.xoml *.cgvp *.mdf "
    "*.csml "
    " *.mmbas *.a66 *.napj *.kbs *.xqr *.eek *.bxb *.exp *.csi *.jscript "
    " *.slackbuild *.a3x *.zcode *.deb *.dfm *.cr *.cu *.applescript *.xba "
    "*.a "
    " *.as3 *.wspd *.dsp *.xje *.hrh *.inc *.fpc *.ccbjs *.dwp *.xbap "
    " *.ssml *.nunit *.php6 *.tsc *.has *.capfile *.njk *.zpk *.wdk "
    "*.generictest "
    " *.triple-s *.clw *.hhh *.d2j *.irbrc *.fsb *.bcf *.sb *.litcoffee "
    "*.mlsxml "
    " *.lbj *.bdsproj *.csm *.builder *.xmla *.fxh *.defi *.f77 *.fbp6 "
    "*.xcodeproj "
    " *.dbpro *.borland *.s2s *.mrm *.pem *.dsq *.xbl *.dbproj *.ccp *.kml "
    " *.js *.plc *.h6h *.ecorediag *.ls3proj *.pl5 *.lasso *.pgm *.~df "
    "*.iss "
    " *.skp *.tcz *.dtml *.php5 *.dor *.spr *.dcr *.vce *.nbk *.clp "
    " *.wcm *.xap *.sdsb *.ht4 *.xpgt *.dsr *.ghc *.dht *.fwactionb *.csp "
    " *.zsc *.clips *.p *.spx *.wax *.pf0 *.opx *.tab *.tiprogram *.vxml "
    " *.uem *.pf4 *.gsc *.kumac *.avc *.cpy *.rip *.zbi *.pas *.arscript "
    " *.msil *.smm *.vps *.galaxy *.poix *.lsxtproj *.iwb *.gml *.tmo *.wis "
    " *.hay *.pm6 *.sbs *.mvpl *.shfb *.aar *.fzs *.con *.usp *.cl "
    " *.zh_tw *.cls *.msh2xml *.qdl *.tst *.swt *.actproj *.rpj *.jgc *.rrh "
    " *.vsprops *.uit *.fdo *.bsh *.nspj *.module *.rsp *.dsa *.lib *.mpm "
    " *.judo *.pf2 *.psc2 *.tplt *.ice *.cya *.sct *.sci *.beam *.netboot "
    " *.script editor *.xql *.sjs *.sce *.f *.aplt *.aks *.mcp *.sdi *.il "
    " *.pgml *.actx *.ps2xml *.tcx *.sit *.vc *.hh *.mfcribbon-ms *.oplm "
    "*.sxv "
    " *.qlc *.dsym *.b *.cap *.fxcproj *.jpx *.hpp *.mtp *.pike *.snp "
    " *.kl3 *.apg *.docstates *.drc *.abs *.textile *.abl *.gml *.phpproj "
    "*.vic "
    " *.acm *.apt *.nokogiri *.wzs *.policy *.mex *.xsc *.cnt *.php4 *.ijs "
    " *.ix3 *.89x *.asc *.is *.pbp *.es *.synw-proj *.rbx *.pls *.rfx "
    " *.ipp *.pm5 *.dd *.dia *.a86 *.cla *.lols *.pdb *.w *.xamlx "
    " *.wod *.avs *.pp *.wmlc *.inc *.sts *.lbi *.ddp *.rexx *.xhtm "
    " *.zs *.nj *.py3 *.pcd *.jetinc *.rb *.usi *.sc *.gld *.mke "
    " *.pd *.pdl *.wmls *.sdef *.t *.qlm *.dxl *.dpr *.wdi *.xys "
    " *.io *.dbo *.ptl *.vc5 *.rbs *.mcw *.akp *.simple *.class *.rsl "
    " *.js *.mdp *.hsc *.jpage *.gla *.frj *.gst *.dms *.sconstruct *.wbs "
    " *.cas *.8xk *.mi *.lo *.lrf *.ocr *.sxt *.lp *.msh2 *.rpp "
    " *.h2o *.mcr *.ml *.msvc *.mbs *.c *.aml *.vfproj *.aro *.pf? "
    " *.sml *.rakefile *.mscr *.mmch *.msh1 *.cljs *.ifp *.chd *.ow *.kpl "
    " *.rprofile *.rpg *.pc *.dmc *.ctp *.dcf *.b *.armx *.alg *.jpd "
    " *.psf *.hbz *.scp *.snapx *.h__ *.ccp *.lng *.robo *.aep *.py "
    " *.plx *.sc *.act *.src *.spt *.nnb *.pl1 *.bps *.i *.mdp "
    " *.i *.yml2 *.mm *.cxl *.fscr *.sma *.cola *.vss *.dt *.wmlsc "
    " *.dml *.asm *.z *.tld *.scptd *.hcw *.app *.tpr *.catscript *.magik "
    " *.texinfo *.c *.ls1 *.slt *.tilemap *.an *.cal *.pika *.art *.mmjs "
    " *.msdl *.pxd *.hydra *.exv *.cod *.con *.npl *.dmb *.lrs *.mscr "
    " *.qx *.ccxml *.tmf *.fgl *.pdl *.ebuild *.jsm *.ssc *.f40 *.dg "
    " *.sfl *.text *.4th *.cod *.rb *.dpr *.cr2 *.jlc *.a51 *.dfm "
    " *.wsd *.androidproj *.wscript *.asproj *.forth *.mpd *.osas *.sym "
    "*.owd *.ff "
    " *.fsf *.h-- *.asbx *.m4x *.nxc *.zcls *.odh *.rpprj *.mingw *.svc "
    " *.mbtemmplate *.csdproj *.sf *.asr *.dts *.dro *.dwt *.gsb *.pds "
    "*.axe "
    " *.rtml *.m *.mingw32 *.rb *.ags *.sqldataprovider *.ptb *.cs *.pde "
    "*.cb "
    " *.sas *.fbz6 *.cuo *.rsm *.psl *.wxs *.dgsl *.pbq *.dws *.cp "
    " *.src *.pdl *.fmt *.pjt *.scx *.yab *.vc7 *.adb *.mli "
    " *.ad2 *.msp *.smx *.mab *.vpl *.ks *.vdt *.asf *.ixx *.xl *.oks "
    " *.eqn *.ssc *.abc *.turboc3 *.mml *.sfm *.ccs *.mbam *.wml *.smi "
    " *.e *.3rf *.nrs *.emakefile *.bltx *.dplt *.fdml *.bms *.cc *.hp? "
    " *.v *.tal *.mod *.ap *.lds *.l *.par *.yajl *.ds *.cdproj "
    " *.atm *.pm *.pvs *.bpk *.epp *.bi *.dpj *.lex *.mst *.wch "
    " *.cus *.bpt *.tml *.pbxscript *.fsproj *.baz *.deployproj *.smd *.mvc "
    "*.bil "
    " *.sc *.xbd *.rapc *.rng *.alx *.tu *.erb *.tcl *.csf *.csview "
    " *.mcr *.car *.iadpage *.wpm *.htd *.awl *.vmx *.kdevprj *.lit "
    "*.tatxtt "
    " *.anm *.vc4 *.ms *.mp? *.mem *.bmml *.plac *.h++ *.msym *.dpk "
    " *.vdm *.92x *.xmta *.wx *.md *.kb *.rsym *.clu *.tag *.seman "
    " *.tpl *.rex *.msm *.cxt *.wsil *.isym *.3dfbat *.scro *.stuffit11task "
    "*.aba "
    " *.mml *.ll *.idb *.mix *.orc *.v4s *.scp *.sbi *.qcf *.cprr "
    " *.bml *.cap *.fsl *.ods *.tem *.d *.atl *.gs *.rtk *.mdf "
    " *.radius *.tom *.pbxbtree *.aut *.db2 *.tlv *.nsconfig *.ic "
    "*.api_filters *.artproj "
    " *.xbc *.xlm4 *.asp+ *.fsscript *.transcriptstyle *.adt *.nlpj "
    "*.fwaction *.sid *.alb "
    " *.bsd *.nunj *.catvbs *.spk *.w32 *.tbasic *.bks *.nopj *.jsl "
    "*.ipproj "
    " *.egg *.pml *.wsym *.qpr *.scr *.mm *.fp *.ds *.as? *.e "
    " *.mpkt *.perlctrl *.unx *.tgproj *.psl *.pxt *.nsx *.xweb4asax *.glf "
    "*.box "
    " *.acr *.lit *.pp *.lnx *.erl *.perlnet *.hsdl *.di *.sscs *.gs "
    " *.xmss *.woa *.pnpt *.plc *.wsrmac *.sar *.c *.tmpl *.imp *.mtx "
    " *.au? *.vscontent *.es *.slogt *.sfr *.dc *.dpq *.vtml *.trs *.des "
    " *.efss *.tokend *.sda *.xsc *.tracwiki *.xojo_project *.h5bprj *.spt "
    "*.ch *.dif "
    " *.scm *.csp *.db *.vad *.cvsrc *.sfp *.xojo_xml_project *.vc2 *.smw "
    "*.irev "
    " *.fpp *.sps *.st *.sw *.gsym *.cva *.codasite *.msct *.celx *.tml "
    " *.ook *.scriptsuite *.msl *.atp *.msdev *.prm *.m *.sqljet *.fdm "
    "*.nunjucks "
    " *.ism *.spt *.axe *.lxsproj *.tbasicc *.psgi *.ddb *.gs *.pxl *.mca "
    " *.hal *.2clk *.alm *.vjsproj *.ephtml *.b *.gcob *.wsp *.cbq *.msl "
    " *.sp? *.cma *.csc *.xct *.uvprjx *.iadclass *.lay *.epj *.kmdi *.e "
    " *.bbproject *.qml *.dsl *.zasm *.djg *.lwmw *.dadx *.gbap *.cmp "
    "*.rguninst "
    " *.adiumscripts *.flm *.pwn *.erubis *.mc *.t *.wmc *.nqc *.wixout "
    "*.tps "
    " *.csp *.netproject *.ifos *.wowproj *.wdx9 *.il *.nppj *.sim *.vc1 "
    "*.amf "
    " *.icl *.boo *.tql *.pcs *.tpx *.xweb4stm *.dgscript *.iadstyle *.l1i "
    "*.rcs "
    " *.jomproj *.rbc *.dil *.xweb4htt *.zfs *.opt *.vspolicy *.wix *.sml "
    "*.xmljet "
    " *.gadgeprj *.vrm *.tal *.win *.ebs *.mli *.ssc *.icn *.vcwin32 *.x "
    " *.m *.db2tr *.perltray *.ll *.ds *.hid *.rbvcp *.ash *.rdoff *.dml "
    " *.rssc *.csgrad *.ccs *.xweb4js *.ept *.gas *.t *.zfrm *.sl *.mc6 "
    " *.qt3d *.pbx5script *.bli *.slogo *.ihex *.umlclass *.ufdl *.rxs *.y "
    "*.graphql "
    " *.m2 *.clx *.pri *.prx *.gnumakefile *.lwa *.db2tbl *.aso *.nms "
    "*.startlet "
    " *.ebs *.agls *.tbasicx *.txc *.adt *.zms *.svx *.lpr *.ss *.das "
    " *.exprwdxsl *.xds *.kg *.xmsc *.sls *.kt3 *.cp *.tpt *.ndpvs "
    "*.perlsvc "
    " *.wsc *.xlm3 *.pyproj *.zsrc *.xweb3master *.exc *.for *.ridl "
    "*.issuite *.ssc "
    " *.xscscpt *.tlc *.cryproject *.idl *.nmpj *.qf *.emakerfile *.db2vw "
    "*.lgt *.fil "
    " *.pxi *.ocamlmakefile *.l *.82p *.ac *.ti *.sbproj *.cbs *.sjava "
    "*.mdsp "
    " *.cesf *.tig *.iadaction *.iadproj *.djconf *.xmap *.aifb "
    "*.propertiesjet *.hevbs *.dbheader "
    " *.ftr *.g1w *.hdl *.nunjs *.inspxeproj *.seestyle *.tes5pas "
    "*.wdgtproj *.urj *.djconfig "
    " *.dwav *.hemcr *.ad *.ads *.eql *.ap? *.djscript *.cp? *.dimg *.mac "
    " *.xmp *.jxl *.no *.gql "
    // by me
    " Makefile .puml"
    ")";
}  // namespace

const char* FilterCreator::defaultTxtFilter() { return defaultFileFilter; }