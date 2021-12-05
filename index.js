const addon = require('bindings')({
  bindings: 'opencv-nodejs',
  // TODO: figure out a better way to do this?
  try: [['module_root', 'cpp', 'build', 'Release', 'bindings']]
})

module.exports = {
  Point2: addon.Point2,
  Size: addon.Size,
  Rect: addon.Rect,
  Vec2: addon.Vec2,
  Vec3: addon.Vec3,
  Vec4: addon.Vec4,
}
