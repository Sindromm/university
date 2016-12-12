var mongoose = require('mongoose');
var table = 'products';
var schema = mongoose.Schema({
	name: {type: String, index: {unique: true}},
	type: {
		name: {type: String, required: true}, 
		description: String
	},
	sell_info: {
		shop_id: {type: mongoose.Schema.Types.ObjectId, ref: 'shops'},
		price: Number,
		amount: Number,
	}
});

module.exports = {
	schema: schema,
	model: mongoose.model(table, schema)
}
