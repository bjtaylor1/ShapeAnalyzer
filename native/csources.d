aasincos.o: aasincos.c
	$(CXX) $(CFLAGS) -c aasincos.c

adjlon.o: adjlon.c
	$(CXX) $(CFLAGS) -c adjlon.c

bch2bps.o: bch2bps.c
	$(CXX) $(CFLAGS) -c bch2bps.c

bchgen.o: bchgen.c
	$(CXX) $(CFLAGS) -c bchgen.c

biveval.o: biveval.c
	$(CXX) $(CFLAGS) -c biveval.c

cs2cs.o: cs2cs.c projects.h proj_api.h emess.h
	$(CXX) $(CFLAGS) -c cs2cs.c

dmstor.o: dmstor.c
	$(CXX) $(CFLAGS) -c dmstor.c

emess.o: emess.c emess.h
	$(CXX) $(CFLAGS) -c emess.c

gen_cheb.o: gen_cheb.c projects.h proj_api.h emess.h
	$(CXX) $(CFLAGS) -c gen_cheb.c

geocent.o: geocent.c geocent.h
	$(CXX) $(CFLAGS) -c geocent.c

geod.o: geod.c projects.h proj_api.h geodesic.h emess.h
	$(CXX) $(CFLAGS) -c geod.c

geod_for.o: geod_for.c projects.h proj_api.h geodesic.h
	$(CXX) $(CFLAGS) -c geod_for.c

geod_inv.o: geod_inv.c projects.h proj_api.h geodesic.h
	$(CXX) $(CFLAGS) -c geod_inv.c

geod_set.o: geod_set.c projects.h proj_api.h geodesic.h emess.h
	$(CXX) $(CFLAGS) -c geod_set.c

jniproj.o: jniproj.c proj_config.h
	$(CXX) $(CFLAGS) -c jniproj.c

mk_cheby.o: mk_cheby.c
	$(CXX) $(CFLAGS) -c mk_cheby.c

multistresstest.o: multistresstest.c proj_api.h
	$(CXX) $(CFLAGS) -c multistresstest.c

nad2bin.o: nad2bin.c
	$(CXX) $(CFLAGS) -c nad2bin.c

nad_cvt.o: nad_cvt.c
	$(CXX) $(CFLAGS) -c nad_cvt.c

nad_init.o: nad_init.c
	$(CXX) $(CFLAGS) -c nad_init.c

nad_intr.o: nad_intr.c
	$(CXX) $(CFLAGS) -c nad_intr.c

PJ_aea.o: PJ_aea.c
	$(CXX) $(CFLAGS) -c PJ_aea.c

PJ_aeqd.o: PJ_aeqd.c
	$(CXX) $(CFLAGS) -c PJ_aeqd.c

PJ_airy.o: PJ_airy.c
	$(CXX) $(CFLAGS) -c PJ_airy.c

PJ_aitoff.o: PJ_aitoff.c
	$(CXX) $(CFLAGS) -c PJ_aitoff.c

pj_apply_gridshift.o: pj_apply_gridshift.c
	$(CXX) $(CFLAGS) -c pj_apply_gridshift.c

pj_apply_vgridshift.o: pj_apply_vgridshift.c
	$(CXX) $(CFLAGS) -c pj_apply_vgridshift.c

PJ_august.o: PJ_august.c
	$(CXX) $(CFLAGS) -c PJ_august.c

pj_auth.o: pj_auth.c
	$(CXX) $(CFLAGS) -c pj_auth.c

PJ_bacon.o: PJ_bacon.c
	$(CXX) $(CFLAGS) -c PJ_bacon.c

PJ_bipc.o: PJ_bipc.c
	$(CXX) $(CFLAGS) -c PJ_bipc.c

PJ_boggs.o: PJ_boggs.c
	$(CXX) $(CFLAGS) -c PJ_boggs.c

PJ_bonne.o: PJ_bonne.c
	$(CXX) $(CFLAGS) -c PJ_bonne.c

PJ_cass.o: PJ_cass.c
	$(CXX) $(CFLAGS) -c PJ_cass.c

PJ_cc.o: PJ_cc.c
	$(CXX) $(CFLAGS) -c PJ_cc.c

PJ_cea.o: PJ_cea.c
	$(CXX) $(CFLAGS) -c PJ_cea.c

PJ_chamb.o: PJ_chamb.c
	$(CXX) $(CFLAGS) -c PJ_chamb.c

PJ_collg.o: PJ_collg.c
	$(CXX) $(CFLAGS) -c PJ_collg.c

PJ_crast.o: PJ_crast.c
	$(CXX) $(CFLAGS) -c PJ_crast.c

pj_ctx.o: pj_ctx.c
	$(CXX) $(CFLAGS) -c pj_ctx.c

pj_datums.o: pj_datums.c
	$(CXX) $(CFLAGS) -c pj_datums.c

pj_datum_set.o: pj_datum_set.c
	$(CXX) $(CFLAGS) -c pj_datum_set.c

PJ_denoy.o: PJ_denoy.c
	$(CXX) $(CFLAGS) -c PJ_denoy.c

pj_deriv.o: pj_deriv.c projects.h proj_api.h
	$(CXX) $(CFLAGS) -c pj_deriv.c

PJ_eck1.o: PJ_eck1.c
	$(CXX) $(CFLAGS) -c PJ_eck1.c

PJ_eck2.o: PJ_eck2.c
	$(CXX) $(CFLAGS) -c PJ_eck2.c

PJ_eck3.o: PJ_eck3.c
	$(CXX) $(CFLAGS) -c PJ_eck3.c

PJ_eck4.o: PJ_eck4.c
	$(CXX) $(CFLAGS) -c PJ_eck4.c

PJ_eck5.o: PJ_eck5.c
	$(CXX) $(CFLAGS) -c PJ_eck5.c

pj_ellps.o: pj_ellps.c projects.h proj_api.h
	$(CXX) $(CFLAGS) -c pj_ellps.c

pj_ell_set.o: pj_ell_set.c
	$(CXX) $(CFLAGS) -c pj_ell_set.c

PJ_eqc.o: PJ_eqc.c
	$(CXX) $(CFLAGS) -c PJ_eqc.c

PJ_eqdc.o: PJ_eqdc.c
	$(CXX) $(CFLAGS) -c PJ_eqdc.c

pj_errno.o: pj_errno.c
	$(CXX) $(CFLAGS) -c pj_errno.c

pj_factors.o: pj_factors.c
	$(CXX) $(CFLAGS) -c pj_factors.c

PJ_fahey.o: PJ_fahey.c
	$(CXX) $(CFLAGS) -c PJ_fahey.c

PJ_fouc_s.o: PJ_fouc_s.c
	$(CXX) $(CFLAGS) -c PJ_fouc_s.c

pj_fwd.o: pj_fwd.c
	$(CXX) $(CFLAGS) -c pj_fwd.c

PJ_gall.o: PJ_gall.c
	$(CXX) $(CFLAGS) -c PJ_gall.c

pj_gauss.o: pj_gauss.c
	$(CXX) $(CFLAGS) -c pj_gauss.c

pj_geocent.o: pj_geocent.c
	$(CXX) $(CFLAGS) -c pj_geocent.c

PJ_geos.o: PJ_geos.c
	$(CXX) $(CFLAGS) -c PJ_geos.c

PJ_gins8.o: PJ_gins8.c
	$(CXX) $(CFLAGS) -c PJ_gins8.c

PJ_gnom.o: PJ_gnom.c
	$(CXX) $(CFLAGS) -c PJ_gnom.c

PJ_gn_sinu.o: PJ_gn_sinu.c
	$(CXX) $(CFLAGS) -c PJ_gn_sinu.c

PJ_goode.o: PJ_goode.c
	$(CXX) $(CFLAGS) -c PJ_goode.c

pj_gridinfo.o: pj_gridinfo.c
	$(CXX) $(CFLAGS) -c pj_gridinfo.c

pj_gridlist.o: pj_gridlist.c
	$(CXX) $(CFLAGS) -c pj_gridlist.c

PJ_gstmerc.o: PJ_gstmerc.c
	$(CXX) $(CFLAGS) -c PJ_gstmerc.c

PJ_hammer.o: PJ_hammer.c
	$(CXX) $(CFLAGS) -c PJ_hammer.c

PJ_hatano.o: PJ_hatano.c
	$(CXX) $(CFLAGS) -c PJ_hatano.c

PJ_healpix.o: PJ_healpix.c
	$(CXX) $(CFLAGS) -c PJ_healpix.c

PJ_igh.o: PJ_igh.c
	$(CXX) $(CFLAGS) -c PJ_igh.c

PJ_imw_p.o: PJ_imw_p.c
	$(CXX) $(CFLAGS) -c PJ_imw_p.c

pj_init.o: pj_init.c
	$(CXX) $(CFLAGS) -c pj_init.c

pj_initcache.o: pj_initcache.c
	$(CXX) $(CFLAGS) -c pj_initcache.c

pj_inv.o: pj_inv.c
	$(CXX) $(CFLAGS) -c pj_inv.c

PJ_isea.o: PJ_isea.c
	$(CXX) $(CFLAGS) -c PJ_isea.c

PJ_krovak.o: PJ_krovak.c
	$(CXX) $(CFLAGS) -c PJ_krovak.c

PJ_labrd.o: PJ_labrd.c
	$(CXX) $(CFLAGS) -c PJ_labrd.c

PJ_laea.o: PJ_laea.c
	$(CXX) $(CFLAGS) -c PJ_laea.c

PJ_lagrng.o: PJ_lagrng.c
	$(CXX) $(CFLAGS) -c PJ_lagrng.c

PJ_larr.o: PJ_larr.c
	$(CXX) $(CFLAGS) -c PJ_larr.c

PJ_lask.o: PJ_lask.c
	$(CXX) $(CFLAGS) -c PJ_lask.c

pj_latlong.o: pj_latlong.c
	$(CXX) $(CFLAGS) -c pj_latlong.c

PJ_lcca.o: PJ_lcca.c
	$(CXX) $(CFLAGS) -c PJ_lcca.c

PJ_lcc.o: PJ_lcc.c
	$(CXX) $(CFLAGS) -c PJ_lcc.c

pj_list.o: pj_list.c projects.h proj_api.h pj_list.h
	$(CXX) $(CFLAGS) -c pj_list.c

pj_log.o: pj_log.c
	$(CXX) $(CFLAGS) -c pj_log.c

PJ_loxim.o: PJ_loxim.c
	$(CXX) $(CFLAGS) -c PJ_loxim.c

PJ_lsat.o: PJ_lsat.c
	$(CXX) $(CFLAGS) -c PJ_lsat.c

pj_malloc.o: pj_malloc.c
	$(CXX) $(CFLAGS) -c pj_malloc.c

PJ_mbtfpp.o: PJ_mbtfpp.c
	$(CXX) $(CFLAGS) -c PJ_mbtfpp.c

PJ_mbtfpq.o: PJ_mbtfpq.c
	$(CXX) $(CFLAGS) -c PJ_mbtfpq.c

PJ_mbt_fps.o: PJ_mbt_fps.c
	$(CXX) $(CFLAGS) -c PJ_mbt_fps.c

PJ_merc.o: PJ_merc.c
	$(CXX) $(CFLAGS) -c PJ_merc.c

PJ_mill.o: PJ_mill.c
	$(CXX) $(CFLAGS) -c PJ_mill.c

pj_mlfn.o: pj_mlfn.c
	$(CXX) $(CFLAGS) -c pj_mlfn.c

PJ_mod_ster.o: PJ_mod_ster.c
	$(CXX) $(CFLAGS) -c PJ_mod_ster.c

PJ_moll.o: PJ_moll.c
	$(CXX) $(CFLAGS) -c PJ_moll.c

pj_msfn.o: pj_msfn.c
	$(CXX) $(CFLAGS) -c pj_msfn.c

pj_mutex.o: pj_mutex.c
	$(CXX) $(CFLAGS) -c pj_mutex.c

PJ_natearth.o: PJ_natearth.c
	$(CXX) $(CFLAGS) -c PJ_natearth.c

PJ_nell.o: PJ_nell.c
	$(CXX) $(CFLAGS) -c PJ_nell.c

PJ_nell_h.o: PJ_nell_h.c
	$(CXX) $(CFLAGS) -c PJ_nell_h.c

PJ_nocol.o: PJ_nocol.c
	$(CXX) $(CFLAGS) -c PJ_nocol.c

PJ_nsper.o: PJ_nsper.c
	$(CXX) $(CFLAGS) -c PJ_nsper.c

PJ_nzmg.o: PJ_nzmg.c
	$(CXX) $(CFLAGS) -c PJ_nzmg.c

PJ_ob_tran.o: PJ_ob_tran.c
	$(CXX) $(CFLAGS) -c PJ_ob_tran.c

PJ_ocea.o: PJ_ocea.c
	$(CXX) $(CFLAGS) -c PJ_ocea.c

PJ_oea.o: PJ_oea.c
	$(CXX) $(CFLAGS) -c PJ_oea.c

PJ_omerc.o: PJ_omerc.c
	$(CXX) $(CFLAGS) -c PJ_omerc.c

pj_open_lib.o: pj_open_lib.c
	$(CXX) $(CFLAGS) -c pj_open_lib.c

PJ_ortho.o: PJ_ortho.c
	$(CXX) $(CFLAGS) -c PJ_ortho.c

pj_param.o: pj_param.c
	$(CXX) $(CFLAGS) -c pj_param.c

pj_phi2.o: pj_phi2.c
	$(CXX) $(CFLAGS) -c pj_phi2.c

PJ_poly.o: PJ_poly.c
	$(CXX) $(CFLAGS) -c PJ_poly.c

pj_pr_list.o: pj_pr_list.c
	$(CXX) $(CFLAGS) -c pj_pr_list.c

PJ_putp2.o: PJ_putp2.c
	$(CXX) $(CFLAGS) -c PJ_putp2.c

PJ_putp3.o: PJ_putp3.c
	$(CXX) $(CFLAGS) -c PJ_putp3.c

PJ_putp4p.o: PJ_putp4p.c
	$(CXX) $(CFLAGS) -c PJ_putp4p.c

PJ_putp5.o: PJ_putp5.c
	$(CXX) $(CFLAGS) -c PJ_putp5.c

PJ_putp6.o: PJ_putp6.c
	$(CXX) $(CFLAGS) -c PJ_putp6.c

pj_qsfn.o: pj_qsfn.c
	$(CXX) $(CFLAGS) -c pj_qsfn.c

pj_release.o: pj_release.c
	$(CXX) $(CFLAGS) -c pj_release.c

PJ_robin.o: PJ_robin.c
	$(CXX) $(CFLAGS) -c PJ_robin.c

PJ_rpoly.o: PJ_rpoly.c
	$(CXX) $(CFLAGS) -c PJ_rpoly.c

PJ_sconics.o: PJ_sconics.c
	$(CXX) $(CFLAGS) -c PJ_sconics.c

PJ_somerc.o: PJ_somerc.c
	$(CXX) $(CFLAGS) -c PJ_somerc.c

PJ_sterea.o: PJ_sterea.c
	$(CXX) $(CFLAGS) -c PJ_sterea.c

PJ_stere.o: PJ_stere.c
	$(CXX) $(CFLAGS) -c PJ_stere.c

pj_strerrno.o: pj_strerrno.c projects.h proj_api.h
	$(CXX) $(CFLAGS) -c pj_strerrno.c

PJ_sts.o: PJ_sts.c
	$(CXX) $(CFLAGS) -c PJ_sts.c

PJ_tcc.o: PJ_tcc.c
	$(CXX) $(CFLAGS) -c PJ_tcc.c

PJ_tcea.o: PJ_tcea.c
	$(CXX) $(CFLAGS) -c PJ_tcea.c

PJ_tmerc.o: PJ_tmerc.c
	$(CXX) $(CFLAGS) -c PJ_tmerc.c

PJ_tpeqd.o: PJ_tpeqd.c
	$(CXX) $(CFLAGS) -c PJ_tpeqd.c

pj_transform.o: pj_transform.c geocent.h
	$(CXX) $(CFLAGS) -c pj_transform.c

pj_tsfn.o: pj_tsfn.c
	$(CXX) $(CFLAGS) -c pj_tsfn.c

pj_units.o: pj_units.c
	$(CXX) $(CFLAGS) -c pj_units.c

PJ_urm5.o: PJ_urm5.c
	$(CXX) $(CFLAGS) -c PJ_urm5.c

PJ_urmfps.o: PJ_urmfps.c
	$(CXX) $(CFLAGS) -c PJ_urmfps.c

pj_utils.o: pj_utils.c
	$(CXX) $(CFLAGS) -c pj_utils.c

PJ_vandg2.o: PJ_vandg2.c
	$(CXX) $(CFLAGS) -c PJ_vandg2.c

PJ_vandg4.o: PJ_vandg4.c
	$(CXX) $(CFLAGS) -c PJ_vandg4.c

PJ_vandg.o: PJ_vandg.c
	$(CXX) $(CFLAGS) -c PJ_vandg.c

PJ_wag2.o: PJ_wag2.c
	$(CXX) $(CFLAGS) -c PJ_wag2.c

PJ_wag3.o: PJ_wag3.c
	$(CXX) $(CFLAGS) -c PJ_wag3.c

PJ_wag7.o: PJ_wag7.c
	$(CXX) $(CFLAGS) -c PJ_wag7.c

PJ_wink1.o: PJ_wink1.c
	$(CXX) $(CFLAGS) -c PJ_wink1.c

PJ_wink2.o: PJ_wink2.c
	$(CXX) $(CFLAGS) -c PJ_wink2.c

pj_zpoly1.o: pj_zpoly1.c
	$(CXX) $(CFLAGS) -c pj_zpoly1.c

proj.o: proj.c projects.h proj_api.h emess.h
	$(CXX) $(CFLAGS) -c proj.c

proj_etmerc.o: proj_etmerc.c
	$(CXX) $(CFLAGS) -c proj_etmerc.c

proj_mdist.o: proj_mdist.c
	$(CXX) $(CFLAGS) -c proj_mdist.c

proj_rouss.o: proj_rouss.c
	$(CXX) $(CFLAGS) -c proj_rouss.c

p_series.o: p_series.c projects.h proj_api.h
	$(CXX) $(CFLAGS) -c p_series.c

rtodms.o: rtodms.c
	$(CXX) $(CFLAGS) -c rtodms.c

vector1.o: vector1.c
	$(CXX) $(CFLAGS) -c vector1.c

