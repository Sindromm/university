#!/bin/bash

. ./env

cp "$ORADATA/logs/"* "$REP_ORADATA/logs"

sqlplus / as sysdba @update.sql
