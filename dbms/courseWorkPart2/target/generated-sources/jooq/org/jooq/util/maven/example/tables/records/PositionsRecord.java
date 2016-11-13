/**
 * This class is generated by jOOQ
 */
package org.jooq.util.maven.example.tables.records;


import javax.annotation.Generated;

import org.jooq.Field;
import org.jooq.Record1;
import org.jooq.Record3;
import org.jooq.Row3;
import org.jooq.impl.UpdatableRecordImpl;
import org.jooq.util.maven.example.tables.Positions;


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
public class PositionsRecord extends UpdatableRecordImpl<PositionsRecord> implements Record3<Integer, String, String> {

    private static final long serialVersionUID = -2115805465;

    /**
     * Setter for <code>public.positions.position_id</code>.
     */
    public void setPositionId(Integer value) {
        set(0, value);
    }

    /**
     * Getter for <code>public.positions.position_id</code>.
     */
    public Integer getPositionId() {
        return (Integer) get(0);
    }

    /**
     * Setter for <code>public.positions.name</code>.
     */
    public void setName(String value) {
        set(1, value);
    }

    /**
     * Getter for <code>public.positions.name</code>.
     */
    public String getName() {
        return (String) get(1);
    }

    /**
     * Setter for <code>public.positions.description</code>.
     */
    public void setDescription(String value) {
        set(2, value);
    }

    /**
     * Getter for <code>public.positions.description</code>.
     */
    public String getDescription() {
        return (String) get(2);
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
    // Record3 type implementation
    // -------------------------------------------------------------------------

    /**
     * {@inheritDoc}
     */
    @Override
    public Row3<Integer, String, String> fieldsRow() {
        return (Row3) super.fieldsRow();
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public Row3<Integer, String, String> valuesRow() {
        return (Row3) super.valuesRow();
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public Field<Integer> field1() {
        return Positions.POSITIONS.POSITION_ID;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public Field<String> field2() {
        return Positions.POSITIONS.NAME;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public Field<String> field3() {
        return Positions.POSITIONS.DESCRIPTION;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public Integer value1() {
        return getPositionId();
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public String value2() {
        return getName();
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public String value3() {
        return getDescription();
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public PositionsRecord value1(Integer value) {
        setPositionId(value);
        return this;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public PositionsRecord value2(String value) {
        setName(value);
        return this;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public PositionsRecord value3(String value) {
        setDescription(value);
        return this;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public PositionsRecord values(Integer value1, String value2, String value3) {
        value1(value1);
        value2(value2);
        value3(value3);
        return this;
    }

    // -------------------------------------------------------------------------
    // Constructors
    // -------------------------------------------------------------------------

    /**
     * Create a detached PositionsRecord
     */
    public PositionsRecord() {
        super(Positions.POSITIONS);
    }

    /**
     * Create a detached, initialised PositionsRecord
     */
    public PositionsRecord(Integer positionId, String name, String description) {
        super(Positions.POSITIONS);

        set(0, positionId);
        set(1, name);
        set(2, description);
    }
}
