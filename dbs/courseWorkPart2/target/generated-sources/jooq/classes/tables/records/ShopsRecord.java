/**
 * This class is generated by jOOQ
 */
package classes.tables.records;


import classes.tables.Shops;

import javax.annotation.Generated;

import org.jooq.Field;
import org.jooq.Record1;
import org.jooq.Record2;
import org.jooq.Row2;
import org.jooq.impl.UpdatableRecordImpl;


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
public class ShopsRecord extends UpdatableRecordImpl<ShopsRecord> implements Record2<Integer, String> {

    private static final long serialVersionUID = -1610393835;

    /**
     * Setter for <code>public.shops.shop_id</code>.
     */
    public void setShopId(Integer value) {
        set(0, value);
    }

    /**
     * Getter for <code>public.shops.shop_id</code>.
     */
    public Integer getShopId() {
        return (Integer) get(0);
    }

    /**
     * Setter for <code>public.shops.street</code>.
     */
    public void setStreet(String value) {
        set(1, value);
    }

    /**
     * Getter for <code>public.shops.street</code>.
     */
    public String getStreet() {
        return (String) get(1);
    }

    // -------------------------------------------------------------------------
    // Primary key information
    // -------------------------------------------------------------------------

    /**
     * {@inheritDoc}
     */
    @Override
    public Record1<Integer> key() {
        return (Record1) super.key();
    }

    // -------------------------------------------------------------------------
    // Record2 type implementation
    // -------------------------------------------------------------------------

    /**
     * {@inheritDoc}
     */
    @Override
    public Row2<Integer, String> fieldsRow() {
        return (Row2) super.fieldsRow();
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public Row2<Integer, String> valuesRow() {
        return (Row2) super.valuesRow();
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public Field<Integer> field1() {
        return Shops.SHOPS.SHOP_ID;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public Field<String> field2() {
        return Shops.SHOPS.STREET;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public Integer value1() {
        return getShopId();
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public String value2() {
        return getStreet();
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public ShopsRecord value1(Integer value) {
        setShopId(value);
        return this;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public ShopsRecord value2(String value) {
        setStreet(value);
        return this;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public ShopsRecord values(Integer value1, String value2) {
        value1(value1);
        value2(value2);
        return this;
    }

    // -------------------------------------------------------------------------
    // Constructors
    // -------------------------------------------------------------------------

    /**
     * Create a detached ShopsRecord
     */
    public ShopsRecord() {
        super(Shops.SHOPS);
    }

    /**
     * Create a detached, initialised ShopsRecord
     */
    public ShopsRecord(Integer shopId, String street) {
        super(Shops.SHOPS);

        set(0, shopId);
        set(1, street);
    }
}