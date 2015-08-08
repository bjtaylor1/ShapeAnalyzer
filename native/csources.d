aasincos.o: aasincos.c
	$(CC) $(CFLAGS) -c aasincos.c

adjlon.o: adjlon.c
	$(CC) $(CFLAGS) -c adjlon.c

bch2bps.o: bch2bps.c
	$(CC) $(CFLAGS) -c bch2bps.c

bchgen.o: bchgen.c
	$(CC) $(CFLAGS) -c bchgen.c

biveval.o: biveval.c
	$(CC) $(CFLAGS) -c biveval.c

dmstor.o: dmstor.c
	$(CC) $(CFLAGS) -c dmstor.c

emess.o: emess.c emess.h
	$(CC) $(CFLAGS) -c emess.c

gen_cheb.o: gen_cheb.c projects.h proj_api.h emess.h
	$(CC) $(CFLAGS) -c gen_cheb.c

geocent.o: geocent.c geocent.h
	$(CC) $(CFLAGS) -c geocent.c

geod_for.o: geod_for.c projects.h proj_api.h geodesic.h
	$(CC) $(CFLAGS) -c geod_for.c

geod_inv.o: geod_inv.c projects.h proj_api.h geodesic.h
	$(CC) $(CFLAGS) -c geod_inv.c

geod_set.o: geod_set.c projects.h proj_api.h geodesic.h emess.h
	$(CC) $(CFLAGS) -c geod_set.c

jniproj.o: jniproj.c proj_config.h
	$(CC) $(CFLAGS) -c jniproj.c

mk_cheby.o: mk_cheby.c
	$(CC) $(CFLAGS) -c mk_cheby.c

nad_cvt.o: nad_cvt.c
	$(CC) $(CFLAGS) -c nad_cvt.c

nad_init.o: nad_init.c
	$(CC) $(CFLAGS) -c nad_init.c

nad_intr.o: nad_intr.c
	$(CC) $(CFLAGS) -c nad_intr.c

PJ_aea.o: PJ_aea.c
	$(CC) $(CFLAGS) -c PJ_aea.c

PJ_aeqd.o: PJ_aeqd.c
	$(CC) $(CFLAGS) -c PJ_aeqd.c

PJ_airy.o: PJ_airy.c
	$(CC) $(CFLAGS) -c PJ_airy.c

PJ_aitoff.o: PJ_aitoff.c
	$(CC) $(CFLAGS) -c PJ_aitoff.c

pj_apply_gridshift.o: pj_apply_gridshift.c
	$(CC) $(CFLAGS) -c pj_apply_gridshift.c

pj_apply_vgridshift.o: pj_apply_vgridshift.c
	$(CC) $(CFLAGS) -c pj_apply_vgridshift.c

PJ_august.o: PJ_august.c
	$(CC) $(CFLAGS) -c PJ_august.c

pj_auth.o: pj_auth.c
	$(CC) $(CFLAGS) -c pj_auth.c

PJ_bacon.o: PJ_bacon.c
	$(CC) $(CFLAGS) -c PJ_bacon.c

PJ_bipc.o: PJ_bipc.c
	$(CC) $(CFLAGS) -c PJ_bipc.c

PJ_boggs.o: PJ_boggs.c
	$(CC) $(CFLAGS) -c PJ_boggs.c

PJ_bonne.o: PJ_bonne.c
	$(CC) $(CFLAGS) -c PJ_bonne.c

PJ_cass.o: PJ_cass.c
	$(CC) $(CFLAGS) -c PJ_cass.c

PJ_cc.o: PJ_cc.c
	$(CC) $(CFLAGS) -c PJ_cc.c

PJ_cea.o: PJ_cea.c
	$(CC) $(CFLAGS) -c PJ_cea.c

PJ_chamb.o: PJ_chamb.c
	$(CC) $(CFLAGS) -c PJ_chamb.c

PJ_collg.o: PJ_collg.c
	$(CC) $(CFLAGS) -c PJ_collg.c

PJ_crast.o: PJ_crast.c
	$(CC) $(CFLAGS) -c PJ_crast.c

pj_ctx.o: pj_ctx.c
	$(CC) $(CFLAGS) -c pj_ctx.c

pj_datums.o: pj_datums.c
	$(CC) $(CFLAGS) -c pj_datums.c

pj_datum_set.o: pj_datum_set.c
	$(CC) $(CFLAGS) -c pj_datum_set.c

PJ_denoy.o: PJ_denoy.c
	$(CC) $(CFLAGS) -c PJ_denoy.c

pj_deriv.o: pj_deriv.c projects.h proj_api.h
	$(CC) $(CFLAGS) -c pj_deriv.c

PJ_eck1.o: PJ_eck1.c
	$(CC) $(CFLAGS) -c PJ_eck1.c

PJ_eck2.o: PJ_eck2.c
	$(CC) $(CFLAGS) -c PJ_eck2.c

PJ_eck3.o: PJ_eck3.c
	$(CC) $(CFLAGS) -c PJ_eck3.c

PJ_eck4.o: PJ_eck4.c
	$(CC) $(CFLAGS) -c PJ_eck4.c

PJ_eck5.o: PJ_eck5.c
	$(CC) $(CFLAGS) -c PJ_eck5.c

pj_ellps.o: pj_ellps.c projects.h proj_api.h
	$(CC) $(CFLAGS) -c pj_ellps.c

pj_ell_set.o: pj_ell_set.c
	$(CC) $(CFLAGS) -c pj_ell_set.c

PJ_eqc.o: PJ_eqc.c
	$(CC) $(CFLAGS) -c PJ_eqc.c

PJ_eqdc.o: PJ_eqdc.c
	$(CC) $(CFLAGS) -c PJ_eqdc.c

pj_errno.o: pj_errno.c
	$(CC) $(CFLAGS) -c pj_errno.c

pj_factors.o: pj_factors.c
	$(CC) $(CFLAGS) -c pj_factors.c

PJ_fahey.o: PJ_fahey.c
	$(CC) $(CFLAGS) -c PJ_fahey.c

PJ_fouc_s.o: PJ_fouc_s.c
	$(CC) $(CFLAGS) -c PJ_fouc_s.c

pj_fwd.o: pj_fwd.c
	$(CC) $(CFLAGS) -c pj_fwd.c

PJ_gall.o: PJ_gall.c
	$(CC) $(CFLAGS) -c PJ_gall.c

pj_gauss.o: pj_gauss.c
	$(CC) $(CFLAGS) -c pj_gauss.c

pj_geocent.o: pj_geocent.c
	$(CC) $(CFLAGS) -c pj_geocent.c

PJ_geos.o: PJ_geos.c
	$(CC) $(CFLAGS) -c PJ_geos.c

PJ_gins8.o: PJ_gins8.c
	$(CC) $(CFLAGS) -c PJ_gins8.c

PJ_gnom.o: PJ_gnom.c
	$(CC) $(CFLAGS) -c PJ_gnom.c

PJ_gn_sinu.o: PJ_gn_sinu.c
	$(CC) $(CFLAGS) -c PJ_gn_sinu.c

PJ_goode.o: PJ_goode.c
	$(CC) $(CFLAGS) -c PJ_goode.c

pj_gridinfo.o: pj_gridinfo.c
	$(CC) $(CFLAGS) -c pj_gridinfo.c

pj_gridlist.o: pj_gridlist.c
	$(CC) $(CFLAGS) -c pj_gridlist.c

PJ_gstmerc.o: PJ_gstmerc.c
	$(CC) $(CFLAGS) -c PJ_gstmerc.c

PJ_hammer.o: PJ_hammer.c
	$(CC) $(CFLAGS) -c PJ_hammer.c

PJ_hatano.o: PJ_hatano.c
	$(CC) $(CFLAGS) -c PJ_hatano.c

PJ_healpix.o: PJ_healpix.c
	$(CC) $(CFLAGS) -c PJ_healpix.c

PJ_igh.o: PJ_igh.c
	$(CC) $(CFLAGS) -c PJ_igh.c

PJ_imw_p.o: PJ_imw_p.c
	$(CC) $(CFLAGS) -c PJ_imw_p.c

pj_init.o: pj_init.c
	$(CC) $(CFLAGS) -c pj_init.c

pj_initcache.o: pj_initcache.c
	$(CC) $(CFLAGS) -c pj_initcache.c

pj_inv.o: pj_inv.c
	$(CC) $(CFLAGS) -c pj_inv.c

PJ_isea.o: PJ_isea.c
	$(CC) $(CFLAGS) -c PJ_isea.c

PJ_krovak.o: PJ_krovak.c
	$(CC) $(CFLAGS) -c PJ_krovak.c

PJ_labrd.o: PJ_labrd.c
	$(CC) $(CFLAGS) -c PJ_labrd.c

PJ_laea.o: PJ_laea.c
	$(CC) $(CFLAGS) -c PJ_laea.c

PJ_lagrng.o: PJ_lagrng.c
	$(CC) $(CFLAGS) -c PJ_lagrng.c

PJ_larr.o: PJ_larr.c
	$(CC) $(CFLAGS) -c PJ_larr.c

PJ_lask.o: PJ_lask.c
	$(CC) $(CFLAGS) -c PJ_lask.c

pj_latlong.o: pj_latlong.c
	$(CC) $(CFLAGS) -c pj_latlong.c

PJ_lcca.o: PJ_lcca.c
	$(CC) $(CFLAGS) -c PJ_lcca.c

PJ_lcc.o: PJ_lcc.c
	$(CC) $(CFLAGS) -c PJ_lcc.c

pj_list.o: pj_list.c projects.h proj_api.h pj_list.h
	$(CC) $(CFLAGS) -c pj_list.c

pj_log.o: pj_log.c
	$(CC) $(CFLAGS) -c pj_log.c

PJ_loxim.o: PJ_loxim.c
	$(CC) $(CFLAGS) -c PJ_loxim.c

PJ_lsat.o: PJ_lsat.c
	$(CC) $(CFLAGS) -c PJ_lsat.c

pj_malloc.o: pj_malloc.c
	$(CC) $(CFLAGS) -c pj_malloc.c

PJ_mbtfpp.o: PJ_mbtfpp.c
	$(CC) $(CFLAGS) -c PJ_mbtfpp.c

PJ_mbtfpq.o: PJ_mbtfpq.c
	$(CC) $(CFLAGS) -c PJ_mbtfpq.c

PJ_mbt_fps.o: PJ_mbt_fps.c
	$(CC) $(CFLAGS) -c PJ_mbt_fps.c

PJ_merc.o: PJ_merc.c
	$(CC) $(CFLAGS) -c PJ_merc.c

PJ_mill.o: PJ_mill.c
	$(CC) $(CFLAGS) -c PJ_mill.c

pj_mlfn.o: pj_mlfn.c
	$(CC) $(CFLAGS) -c pj_mlfn.c

PJ_mod_ster.o: PJ_mod_ster.c
	$(CC) $(CFLAGS) -c PJ_mod_ster.c

PJ_moll.o: PJ_moll.c
	$(CC) $(CFLAGS) -c PJ_moll.c

pj_msfn.o: pj_msfn.c
	$(CC) $(CFLAGS) -c pj_msfn.c

pj_mutex.o: pj_mutex.c
	$(CC) $(CFLAGS) -c pj_mutex.c

PJ_natearth.o: PJ_natearth.c
	$(CC) $(CFLAGS) -c PJ_natearth.c

PJ_nell.o: PJ_nell.c
	$(CC) $(CFLAGS) -c PJ_nell.c

PJ_nell_h.o: PJ_nell_h.c
	$(CC) $(CFLAGS) -c PJ_nell_h.c

PJ_nocol.o: PJ_nocol.c
	$(CC) $(CFLAGS) -c PJ_nocol.c

PJ_nsper.o: PJ_nsper.c
	$(CC) $(CFLAGS) -c PJ_nsper.c

PJ_nzmg.o: PJ_nzmg.c
	$(CC) $(CFLAGS) -c PJ_nzmg.c

PJ_ob_tran.o: PJ_ob_tran.c
	$(CC) $(CFLAGS) -c PJ_ob_tran.c

PJ_ocea.o: PJ_ocea.c
	$(CC) $(CFLAGS) -c PJ_ocea.c

PJ_oea.o: PJ_oea.c
	$(CC) $(CFLAGS) -c PJ_oea.c

PJ_omerc.o: PJ_omerc.c
	$(CC) $(CFLAGS) -c PJ_omerc.c

PJ_ortho.o: PJ_ortho.c
	$(CC) $(CFLAGS) -c PJ_ortho.c

pj_param.o: pj_param.c
	$(CC) $(CFLAGS) -c pj_param.c

pj_phi2.o: pj_phi2.c
	$(CC) $(CFLAGS) -c pj_phi2.c

PJ_poly.o: PJ_poly.c
	$(CC) $(CFLAGS) -c PJ_poly.c

pj_pr_list.o: pj_pr_list.c
	$(CC) $(CFLAGS) -c pj_pr_list.c

PJ_putp2.o: PJ_putp2.c
	$(CC) $(CFLAGS) -c PJ_putp2.c

PJ_putp3.o: PJ_putp3.c
	$(CC) $(CFLAGS) -c PJ_putp3.c

PJ_putp4p.o: PJ_putp4p.c
	$(CC) $(CFLAGS) -c PJ_putp4p.c

PJ_putp5.o: PJ_putp5.c
	$(CC) $(CFLAGS) -c PJ_putp5.c

PJ_putp6.o: PJ_putp6.c
	$(CC) $(CFLAGS) -c PJ_putp6.c

pj_qsfn.o: pj_qsfn.c
	$(CC) $(CFLAGS) -c pj_qsfn.c

pj_release.o: pj_release.c
	$(CC) $(CFLAGS) -c pj_release.c

PJ_robin.o: PJ_robin.c
	$(CC) $(CFLAGS) -c PJ_robin.c

PJ_rpoly.o: PJ_rpoly.c
	$(CC) $(CFLAGS) -c PJ_rpoly.c

PJ_sconics.o: PJ_sconics.c
	$(CC) $(CFLAGS) -c PJ_sconics.c

PJ_somerc.o: PJ_somerc.c
	$(CC) $(CFLAGS) -c PJ_somerc.c

PJ_sterea.o: PJ_sterea.c
	$(CC) $(CFLAGS) -c PJ_sterea.c

PJ_stere.o: PJ_stere.c
	$(CC) $(CFLAGS) -c PJ_stere.c

pj_strerrno.o: pj_strerrno.c projects.h proj_api.h
	$(CC) $(CFLAGS) -c pj_strerrno.c

PJ_sts.o: PJ_sts.c
	$(CC) $(CFLAGS) -c PJ_sts.c

PJ_tcc.o: PJ_tcc.c
	$(CC) $(CFLAGS) -c PJ_tcc.c

PJ_tcea.o: PJ_tcea.c
	$(CC) $(CFLAGS) -c PJ_tcea.c

PJ_tmerc.o: PJ_tmerc.c
	$(CC) $(CFLAGS) -c PJ_tmerc.c

PJ_tpeqd.o: PJ_tpeqd.c
	$(CC) $(CFLAGS) -c PJ_tpeqd.c

pj_transform.o: pj_transform.c geocent.h
	$(CC) $(CFLAGS) -c pj_transform.c

pj_tsfn.o: pj_tsfn.c
	$(CC) $(CFLAGS) -c pj_tsfn.c

pj_units.o: pj_units.c
	$(CC) $(CFLAGS) -c pj_units.c

PJ_urm5.o: PJ_urm5.c
	$(CC) $(CFLAGS) -c PJ_urm5.c

PJ_urmfps.o: PJ_urmfps.c
	$(CC) $(CFLAGS) -c PJ_urmfps.c

pj_utils.o: pj_utils.c
	$(CC) $(CFLAGS) -c pj_utils.c

PJ_vandg2.o: PJ_vandg2.c
	$(CC) $(CFLAGS) -c PJ_vandg2.c

PJ_vandg4.o: PJ_vandg4.c
	$(CC) $(CFLAGS) -c PJ_vandg4.c

PJ_vandg.o: PJ_vandg.c
	$(CC) $(CFLAGS) -c PJ_vandg.c

PJ_wag2.o: PJ_wag2.c
	$(CC) $(CFLAGS) -c PJ_wag2.c

PJ_wag3.o: PJ_wag3.c
	$(CC) $(CFLAGS) -c PJ_wag3.c

PJ_wag7.o: PJ_wag7.c
	$(CC) $(CFLAGS) -c PJ_wag7.c

PJ_wink1.o: PJ_wink1.c
	$(CC) $(CFLAGS) -c PJ_wink1.c

PJ_wink2.o: PJ_wink2.c
	$(CC) $(CFLAGS) -c PJ_wink2.c

pj_zpoly1.o: pj_zpoly1.c
	$(CC) $(CFLAGS) -c pj_zpoly1.c

proj_etmerc.o: proj_etmerc.c
	$(CC) $(CFLAGS) -c proj_etmerc.c

proj_mdist.o: proj_mdist.c
	$(CC) $(CFLAGS) -c proj_mdist.c

proj_rouss.o: proj_rouss.c
	$(CC) $(CFLAGS) -c proj_rouss.c

p_series.o: p_series.c projects.h proj_api.h
	$(CC) $(CFLAGS) -c p_series.c

rtodms.o: rtodms.c
	$(CC) $(CFLAGS) -c rtodms.c

vector1.o: vector1.c
	$(CC) $(CFLAGS) -c vector1.c

