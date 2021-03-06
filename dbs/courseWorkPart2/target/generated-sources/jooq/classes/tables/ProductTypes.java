/**
 * This class is generated by jOOQ
 */
package classes.tables;


import classes.Keys;
import classes.Public;
import classes.tables.records.ProductTypesRecord;

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
public class ProductTypes extends TableImpl<ProductTypesRecord> {

    private static final long serialVersionUID = 1239038012;

    /**
     * The reference instance of <code>public.product_types</code>
     */
    public static final ProductTypes PRODUCT_TYPES = new ProductTypes();

    /**
     * The class holding records for this type
     */
    @Override
    public Class<ProductTypesRecord> getRecordType() {
        return ProductTypesRecord.class;
    }

    /**
     * The column <code>public.product_types.type_id</code>.
     */
    public final TableField<ProductTypesRecord, Integer> TYPE_ID = createField("type_id", org.jooq.impl.SQLDataType.INTEGER.nullable(false).defaultValue(org.jooq.impl.DSL.field("nextval('product_types_type_id_seq'::regclass)", org.jooq.impl.SQLDataType.INTEGER)), this, "");

    /**
     * The column <code>public.product_types.title</code>.
     */
    public final TableField<ProductTypesRecord, String> TITLE = createField("title", org.jooq.impl.SQLDataType.CLOB.nullable(false), this, "");

    /**
     * The column <code>public.product_types.description</code>.
     */
    public final TableField<ProductTypesRecord, String> DESCRIPTION = createField("description", org.jooq.impl.SQLDataType.CLOB, this, "");

    /**
     * Create a <code>public.product_types</code> table reference
     */
    public ProductTypes() {
        this("product_types", null);
    }

    /**
     * Create an aliased <code>public.product_types</code> table reference
     */
    public ProductTypes(String alias) {
        this(alias, PRODUCT_TYPES);
    }

    private ProductTypes(String alias, Table<ProductTypesRecord> aliased) {
        this(alias, aliased, null);
    }

    private ProductTypes(String alias, Table<ProductTypesRecord> aliased, Field<?>[] parameters) {
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
    public Identity<ProductTypesRecord, Integer> getIdentity() {
        return Keys.IDENTITY_PRODUCT_TYPES;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public UniqueKey<ProductTypesRecord> getPrimaryKey() {
        return Keys.PRODUCT_TYPES_PKEY;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public List<UniqueKey<ProductTypesRecord>> getKeys() {
        return Arrays.<UniqueKey<ProductTypesRecord>>asList(Keys.PRODUCT_TYPES_PKEY, Keys.TITLE_UNIQ_KEY);
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public ProductTypes as(String alias) {
        return new ProductTypes(alias, this);
    }

    /**
     * Rename this table
     */
    public ProductTypes rename(String name) {
        return new ProductTypes(name, null);
    }
}
