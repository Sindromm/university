/**
 * This class is generated by jOOQ
 */
package classes.udt.records;


import classes.udt.Passport;

import javax.annotation.Generated;

import org.jooq.Field;
import org.jooq.Record2;
import org.jooq.Row2;
import org.jooq.impl.UDTRecordImpl;


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
public class PassportRecord extends UDTRecordImpl<PassportRecord> implements Record2<Integer, Integer> {

    private static final long serialVersionUID = -352779129;

    /**
     * Setter for <code>public.passport.serial_number</code>.
     */
    public void setSerialNumber(Integer value) {
        set(0, value);
    }

    /**
     * Getter for <code>public.passport.serial_number</code>.
     */
    public Integer getSerialNumber() {
        return (Integer) get(0);
    }

    /**
     * Setter for <code>public.passport.id</code>.
     */
    public void setId(Integer value) {
        set(1, value);
    }

    /**
     * Getter for <code>public.passport.id</code>.
     */
    public Integer getId() {
        return (Integer) get(1);
    }

    // -------------------------------------------------------------------------
    // Record2 type implementation
    // -------------------------------------------------------------------------

    /**
     * {@inheritDoc}
     */
    @Override
    public Row2<Integer, Integer> fieldsRow() {
        return (Row2) super.fieldsRow();
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public Row2<Integer, Integer> valuesRow() {
        return (Row2) super.valuesRow();
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public Field<Integer> field1() {
        return Passport.SERIAL_NUMBER;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public Field<Integer> field2() {
        return Passport.ID;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public Integer value1() {
        return getSerialNumber();
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public Integer value2() {
        return getId();
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public PassportRecord value1(Integer value) {
        setSerialNumber(value);
        return this;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public PassportRecord value2(Integer value) {
        setId(value);
        return this;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public PassportRecord values(Integer value1, Integer value2) {
        value1(value1);
        value2(value2);
        return this;
    }

    // -------------------------------------------------------------------------
    // Constructors
    // -------------------------------------------------------------------------

    /**
     * Create a detached PassportRecord
     */
    public PassportRecord() {
        super(Passport.PASSPORT);
    }

    /**
     * Create a detached, initialised PassportRecord
     */
    public PassportRecord(Integer serialNumber, Integer id) {
        super(Passport.PASSPORT);

        set(0, serialNumber);
        set(1, id);
    }
}
