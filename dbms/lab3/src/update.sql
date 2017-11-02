startup nomount pfile=inits191954_rep.ora
alter database mount standby database;
recover standby database;
shutdown;
exit;
