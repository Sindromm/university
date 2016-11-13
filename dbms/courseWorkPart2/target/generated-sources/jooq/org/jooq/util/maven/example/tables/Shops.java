/**
 * This class is generated by jOOQ
 */
package org.jooq.util.maven.example.tables;


import java.util.Arrays;
import java.util.List;

import javax.annotation.Generated;

import org.jooq.Field;
import org.jooq.Identity;
import org.jooq.Schema;
import org.jooq.Table;
import org.jooq.TableField;
import org.jooq.UniqueKey;
import org.jooq.impl.TableImpl;
import org.jooq.util.maven.example.Keys;
import org.jooq.util.maven.example.Public;
import org.jooq.util.maven.example.tables.records.ShopsRecord;


/**
 * This class is generated by jOOQ.
 */
@Generated(
    value = {
        "http://www.jooq.org",
        "jOOQ version:3.8.6"
    },
    comments = "This class is generated by jOOQ"
)
@SuppressWarnings({ "all", "unchecked", "rawtypes" })
public class Shops extends TableImpl<ShopsRecord> {

    private static final long serialVersionUID = -890365351;

    /**
     * The reference instance of <code>public.shops</code>
     */
    public static final Shops SHOPS = new Shops();

    /**
     * The class holding records for this type
     */
    @Override
    public Class<ShopsRecord> getRecordType() {
        return ShopsRecord.class;
    }

    /**
     * The column <code>public.shops.shop_id</code>.
     */
    public final TableField<ShopsRecord, Integer> SHOP_ID = createField("shop_id", org.jooq.impl.SQLDataType.INTEGER.nullable(false).defaultValue(org.jooq.impl.DSL.field("nextval('shops_shop_id_seq'::regclass)", org.jooq.impl.SQLDataType.INTEGER)), this, "");

    /**
     * The column <code>public.shops.street</code>.
     */
    public final TableField<ShopsRecord, String> STREET = createField("street", org.jooq.impl.SQLDataType.CLOB.nullable(false), this, "");

    /**
     * Create a <code>public.shops</code> table reference
     */
    public Shops() {
        this("shops", null);
    }

    /**
     * Create an aliased <code>public.shops</code> table reference
     */
    public Shops(String alias) {
        this(alias, SHOPS);
    }

    private Shops(String alias, Table<ShopsRecord> aliased) {
        this(alias, aliased, null);
    }

    private Shops(String alias, Table<ShopsRecord> aliased, Field<?>[] parameters) {
        super(alias, null, aliased, parameters, "");
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public Schema getSchema() {
        return Public.PUBLIC;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public Identity<ShopsRecord, Integer> getIdentity() {
        return Keys.IDENTITY_SHOPS;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public UniqueKey<ShopsRecord> getPrimaryKey() {
        return Keys.SHOPS_PKEY;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public List<UniqueKey<ShopsRecord>> getKeys() {
        return Arrays.<UniqueKey<ShopsRecord>>asList(Keys.SHOPS_PKEY, Keys.STREETS_UNIQ_KEY);
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public Shops as(String alias) {
        return new Shops(alias, this);
    }

    /**
     * Rename this table
     */
    public Shops rename(String name) {
        return new Shops(name, null);
    }
}
