/**
 * This class is generated by jOOQ
 */
package org.jooq.util.maven.example.routines;


import java.sql.Date;

import javax.annotation.Generated;

import org.jooq.Field;
import org.jooq.Parameter;
import org.jooq.impl.AbstractRoutine;
import org.jooq.util.maven.example.Public;


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
public class AddSellLog extends AbstractRoutine<Integer> {

    private static final long serialVersionUID = 1351434055;

    /**
     * The parameter <code>public.add_sell_log.RETURN_VALUE</code>.
     */
    public static final Parameter<Integer> RETURN_VALUE = createParameter("RETURN_VALUE", org.jooq.impl.SQLDataType.INTEGER, false, false);

    /**
     * The parameter <code>public.add_sell_log.p_id</code>.
     */
    public static final Parameter<Integer> P_ID = createParameter("p_id", org.jooq.impl.SQLDataType.INTEGER, false, false);

    /**
     * The parameter <code>public.add_sell_log.sh_id</code>.
     */
    public static final Parameter<Integer> SH_ID = createParameter("sh_id", org.jooq.impl.SQLDataType.INTEGER, false, false);

    /**
     * The parameter <code>public.add_sell_log.in_amount</code>.
     */
    public static final Parameter<Integer> IN_AMOUNT = createParameter("in_amount", org.jooq.impl.SQLDataType.INTEGER, false, false);

    /**
     * The parameter <code>public.add_sell_log.date</code>.
     */
    public static final Parameter<Date> DATE = createParameter("date", org.jooq.impl.SQLDataType.DATE, false, false);

    /**
     * Create a new routine call instance
     */
    public AddSellLog() {
        super("add_sell_log", Public.PUBLIC, org.jooq.impl.SQLDataType.INTEGER);

        setReturnParameter(RETURN_VALUE);
        addInParameter(P_ID);
        addInParameter(SH_ID);
        addInParameter(IN_AMOUNT);
        addInParameter(DATE);
    }

    /**
     * Set the <code>p_id</code> parameter IN value to the routine
     */
    public void setPId(Integer value) {
        setValue(P_ID, value);
    }

    /**
     * Set the <code>p_id</code> parameter to the function to be used with a {@link org.jooq.Select} statement
     */
    public void setPId(Field<Integer> field) {
        setField(P_ID, field);
    }

    /**
     * Set the <code>sh_id</code> parameter IN value to the routine
     */
    public void setShId(Integer value) {
        setValue(SH_ID, value);
    }

    /**
     * Set the <code>sh_id</code> parameter to the function to be used with a {@link org.jooq.Select} statement
     */
    public void setShId(Field<Integer> field) {
        setField(SH_ID, field);
    }

    /**
     * Set the <code>in_amount</code> parameter IN value to the routine
     */
    public void setInAmount(Integer value) {
        setValue(IN_AMOUNT, value);
    }

    /**
     * Set the <code>in_amount</code> parameter to the function to be used with a {@link org.jooq.Select} statement
     */
    public void setInAmount(Field<Integer> field) {
        setField(IN_AMOUNT, field);
    }

    /**
     * Set the <code>date</code> parameter IN value to the routine
     */
    public void setDate(Date value) {
        setValue(DATE, value);
    }

    /**
     * Set the <code>date</code> parameter to the function to be used with a {@link org.jooq.Select} statement
     */
    public void setDate(Field<Date> field) {
        setField(DATE, field);
    }
}
