/**
 * This class is generated by jOOQ
 */
package classes.routines;


import classes.Public;

import javax.annotation.Generated;

import org.jooq.Field;
import org.jooq.Parameter;
import org.jooq.impl.AbstractRoutine;


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
public class AddProductAmount extends AbstractRoutine<Integer> {

    private static final long serialVersionUID = 1429669246;

    /**
     * The parameter <code>public.add_product_amount.RETURN_VALUE</code>.
     */
    public static final Parameter<Integer> RETURN_VALUE = createParameter("RETURN_VALUE", org.jooq.impl.SQLDataType.INTEGER, false, false);

    /**
     * The parameter <code>public.add_product_amount.pr_id</code>.
     */
    public static final Parameter<Integer> PR_ID = createParameter("pr_id", org.jooq.impl.SQLDataType.INTEGER, false, false);

    /**
     * The parameter <code>public.add_product_amount.sh_id</code>.
     */
    public static final Parameter<Integer> SH_ID = createParameter("sh_id", org.jooq.impl.SQLDataType.INTEGER, false, false);

    /**
     * The parameter <code>public.add_product_amount.amount</code>.
     */
    public static final Parameter<Integer> AMOUNT = createParameter("amount", org.jooq.impl.SQLDataType.INTEGER, false, false);

    /**
     * Create a new routine call instance
     */
    public AddProductAmount() {
        super("add_product_amount", Public.PUBLIC, org.jooq.impl.SQLDataType.INTEGER);

        setReturnParameter(RETURN_VALUE);
        addInParameter(PR_ID);
        addInParameter(SH_ID);
        addInParameter(AMOUNT);
    }

    /**
     * Set the <code>pr_id</code> parameter IN value to the routine
     */
    public void setPrId(Integer value) {
        setValue(PR_ID, value);
    }

    /**
     * Set the <code>pr_id</code> parameter to the function to be used with a {@link org.jooq.Select} statement
     */
    public void setPrId(Field<Integer> field) {
        setField(PR_ID, field);
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
     * Set the <code>amount</code> parameter IN value to the routine
     */
    public void setAmount(Integer value) {
        setValue(AMOUNT, value);
    }

    /**
     * Set the <code>amount</code> parameter to the function to be used with a {@link org.jooq.Select} statement
     */
    public void setAmount(Field<Integer> field) {
        setField(AMOUNT, field);
    }
}