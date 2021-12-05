import { Vec3 } from '../../../index'

describe('[core] Vec2', () => {
  describe('constructor', () => {
    it('initializes from numbers', () => {
      const point = new Vec3(1, 2, 3)

      expect(point.x).toStrictEqual(1)
      expect(point.y).toStrictEqual(2)
      expect(point.z).toStrictEqual(3)
    })
  })
})
