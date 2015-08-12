# run this as postgres user, eg:
# imposm-psqldb > create_db.sh; sudo su postgres; sh ./create_db.sh
set -xe
#createuser --no-superuser --no-createrole --createdb osm
createdb -E UTF8 -O osm osm_devon
#createlang plpgsql osm_devon
psql -d osm_devon -f /usr/share/postgresql/9.3/contrib/postgis-2.1/postgis.sql
psql -d osm_devon -f /usr/share/postgresql/9.3/contrib/postgis-2.1/spatial_ref_sys.sql
#psql -d osm_devon -f /usr/local/lib/python2.7/dist-packages/imposm/900913.sql
echo "ALTER TABLE geometry_columns OWNER TO osm;" | psql -d osm_devon
echo "ALTER TABLE spatial_ref_sys OWNER TO osm;" | psql -d osm_devon
echo "ALTER USER osm WITH PASSWORD 'osm';" |psql -d osm_devon
#echo "host	osm_devon	osm	127.0.0.1/32	md5" >> /etc/postgresql/9.3/main/pg_hba.conf
set +x
echo "Done. Don't forget to restart postgresql!"
